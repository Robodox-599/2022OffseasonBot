#include "SwerveModule.h"

SwerveModule::SwerveModule(const double Module[] ):
                                                                                    m_DriveMotor{ (int)Module[0]},
                                                                                    m_AngleMotor{ (int)Module[1] },
                                                                                    m_AngleEncoder{ (int)Module[2] },
                                                                                    m_AngleOffset{ Module[3] },
                                                                                    m_Feedforward{SwerveConstants::DriveKS, SwerveConstants::DriveKV, SwerveConstants::DriveKA}
{
    //Config Angle Encoder
    m_AngleEncoder.ConfigFactoryDefault();
    m_AngleEncoder.ConfigAllSettings(m_Settings.SwerveCanCoderConfig);

    //Config Angle Motor
    m_AngleMotor.ConfigFactoryDefault();
    m_AngleMotor.ConfigAllSettings(m_Settings.SwerveAngleFXConfig);
    m_AngleMotor.SetInverted(SwerveConstants::AngleMotorInvert);
    m_AngleMotor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
    double absolutePosition = DegreesToFalcon(GetCANCoder().Degrees() - m_AngleOffset, SwerveConstants::AngleGearRatio);
    m_AngleMotor.SetSelectedSensorPosition(absolutePosition);

    //Config Drive Motor
    m_DriveMotor.ConfigFactoryDefault();
    m_DriveMotor.ConfigAllSettings(m_Settings.SwerveDriveFXConfig);
    m_DriveMotor.SetInverted(SwerveConstants::DriveMotorInvert);
    m_DriveMotor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
    m_DriveMotor.SetSelectedSensorPosition(0);
    m_DriveMotor.EnableVoltageCompensation(true);

    m_LastAngle = GetState().angle.Degrees();
}

void SwerveModule::SetDesiredState(frc::SwerveModuleState& DesiredState, bool IsOpenLoop){
    DesiredState = Optimize(DesiredState, GetState().angle);
    
    if(IsOpenLoop){
        double PercentOutput = DesiredState.speed / SwerveConstants::MaxSpeed;
        m_DriveMotor.Set(PercentOutput);
    }else{
        double Velocity = MPSToFalcon(DesiredState.speed, SwerveConstants::WheelCircumference, SwerveConstants::DriveGearRatio);  
        double VoltageFeedForward = m_Feedforward.Calculate(DesiredState.speed)/SwerveConstants::kNominal;
        m_DriveMotor.Set(ctre::phoenix::motorcontrol::ControlMode::Velocity, Velocity, ctre::phoenix::motorcontrol::DemandType_ArbitraryFeedForward, VoltageFeedForward);
    }
    units::degree_t Angle = ( abs( DesiredState.speed.value() ) <= SwerveConstants::MaxSpeed.value() * 0.01 ) ? m_LastAngle: DesiredState.angle.Degrees();
    m_AngleMotor.Set( ctre::phoenix::motorcontrol::ControlMode::Position, DegreesToFalcon(Angle, SwerveConstants::AngleGearRatio) );
    m_LastAngle = Angle;
}

/* This custom optimize method is created because Wpilib assumes the controller is continuous, which the CTRE Talons are not. */
frc::SwerveModuleState SwerveModule::Optimize(frc::SwerveModuleState DesiredState, frc::Rotation2d CurrentAngle){
    units::degree_t ModReferenceAngle{ fmod( CurrentAngle.Degrees().value(), 360.0 )};
    units::meters_per_second_t TargetSpeed = DesiredState.speed;
    units::degree_t Delta = ModReferenceAngle - CurrentAngle.Degrees();
    if(Delta >= 270_deg){
        Delta -= 360_deg;
    }else if(Delta <= -270_deg){
        Delta += 360_deg;
    }
    if( abs(Delta.value()) > 90){
        TargetSpeed = - TargetSpeed;
        Delta = Delta > 0_deg ? (Delta -= 180_deg) : ( Delta += 180_deg);
    }
    units::degree_t TargetAngle = CurrentAngle.Degrees() + Delta;
    return  {TargetSpeed, TargetAngle};
}


frc::Rotation2d SwerveModule::GetCANCoder(){
    return frc::Rotation2d( units::degree_t( m_AngleEncoder.GetAbsolutePosition() ) );
}

frc::SwerveModuleState SwerveModule::GetState(){
    units::meters_per_second_t Velocity{ FalconToMPS(m_DriveMotor.GetSelectedSensorVelocity(0), SwerveConstants::WheelCircumference, SwerveConstants::DriveGearRatio) };
    frc::Rotation2d Angle{FalconToDegrees( m_AngleMotor.GetSelectedSensorPosition(), SwerveConstants::AngleGearRatio) };
    return {Velocity, Angle};
}

units::degree_t SwerveModule::FalconToDegrees(double Counts, double GearRatio){
    return units::degree_t(Counts * ( 360.0 / (GearRatio * 2048.0)));
}

double SwerveModule::DegreesToFalcon(units::degree_t Degrees, double GearRatio){
    return Degrees.value() / (360.0 / (GearRatio * 2048.0));
}

double SwerveModule::FalconToRPM(double VelocityCounts, double GearRatio){
    double MotorRPM = VelocityCounts * ( 600.0 / 2048.0);
    double MechRPM = MotorRPM / GearRatio;
    return MechRPM;
}

double SwerveModule::RPMToFalcon(double RPM, double GearRatio){
    double MotorRPM = RPM * GearRatio;
    double SensorCounts = MotorRPM * (2048.0 / 600.0);
    return SensorCounts;
}

units::meters_per_second_t SwerveModule::FalconToMPS(double VelocityCounts, units::meter_t Circumference, double GearRatio){
    double WheelRPM = FalconToRPM(VelocityCounts, GearRatio);
    units::meters_per_second_t WheelMPS = (WheelRPM * Circumference) /60_s;
    return WheelMPS;
}

double SwerveModule::MPSToFalcon(units::meters_per_second_t Velocity, units::meter_t circumference, double GearRatio){
    double WheelRPM = ( Velocity.value() * 60 ) / circumference.value();
    double WheelVelocity = RPMToFalcon(WheelRPM, GearRatio);
    return WheelVelocity;
}
