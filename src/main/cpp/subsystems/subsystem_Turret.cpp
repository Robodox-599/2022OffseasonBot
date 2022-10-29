// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/subsystem_Turret.h"

subsystem_Turret::subsystem_Turret():
m_FlywheelMotor1{ShooterConstants::flywheel1ID}, 
m_FlywheelMotor2{ShooterConstants::flywheel2ID}, 
m_TurretMotor{ShooterConstants::turretID, rev::CANSparkMax::MotorType::kBrushless}, 
m_HoodMotor{ShooterConstants::hoodID, rev::CANSparkMax::MotorType::kBrushless},   
m_TurretEncoder{m_TurretMotor.GetEncoder()},
m_HoodEncoder{m_HoodMotor.GetEncoder()},
m_HoodPID{m_HoodMotor.GetPIDController()},
m_TurretPID{m_TurretMotor.GetPIDController()}
{
//shooter config
  m_FlywheelMotor1.ConfigFactoryDefault();
    // m_FlywheelMotor.ConfigAllSettings(); bleh
    // m_FlywheelMotor.SetInverted();
  m_FlywheelMotor1.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
   m_FlywheelMotor2.ConfigFactoryDefault();
    // m_FlywheelMotor.ConfigAllSettings(); bleh
    // m_FlywheelMotor.SetInverted();
  m_FlywheelMotor2.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
  m_FlywheelMotor2.Follow(m_FlywheelMotor1);
  m_FlywheelMotor2.SetInverted(true);

//sensor config
  m_FlywheelMotor1.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, ShooterConstants::kTimeoutMs);
  m_FlywheelMotor1.SetSensorPhase(true);
  m_FlywheelMotor1.SetSelectedSensorPosition(0, 0, ShooterConstants::kTimeoutMs);
  m_FlywheelMotor2.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, ShooterConstants::kTimeoutMs);
  m_FlywheelMotor2.SetSensorPhase(true);
  m_FlywheelMotor2.SetSelectedSensorPosition(0, 0, ShooterConstants::kTimeoutMs);


//closed loop gains
  m_FlywheelMotor1.Config_kD(0, ShooterConstants::kFlywheelD, ShooterConstants::kTimeoutMs);
  m_FlywheelMotor1.Config_kF(0, ShooterConstants::kFlywheelF, ShooterConstants::kTimeoutMs);
  m_FlywheelMotor1.Config_kI(0, ShooterConstants::kFlywheelI, ShooterConstants::kTimeoutMs);
  m_FlywheelMotor1.Config_kP(0, ShooterConstants::kFlywheelP, ShooterConstants::kTimeoutMs);
  m_FlywheelMotor1.SelectProfileSlot(0, 0);

//   m_FlywheelMotor2.Config_kD(0, ShooterConstants::kFlywheelD, ShooterConstants::kTimeoutMs);
//   m_FlywheelMotor2.Config_kF(0, ShooterConstants::kFlywheelF, ShooterConstants::kTimeoutMs);
//   m_FlywheelMotor2.Config_kI(0, ShooterConstants::kFlywheelI, ShooterConstants::kTimeoutMs);
//   m_FlywheelMotor2.Config_kP(0, ShooterConstants::kFlywheelP, ShooterConstants::kTimeoutMs);
  m_FlywheelMotor2.SelectProfileSlot(0, 0);

  m_HoodMotor.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  m_HoodMotor.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward, 12);
  
  m_HoodPID.SetP(ShooterConstants::kHoodP);
//   m_HoodPID.SetI(ShooterConstants::kHoodI);
//   m_HoodPID.SetD(ShooterConstants::kHoodD);

  m_TurretPID.SetP(ShooterConstants::kAimP);
  m_TurretPID.SetI(ShooterConstants::kAimI);
  m_TurretPID.SetD(ShooterConstants::kAimD);
}

void subsystem_Turret::aimAtTarget() {
    if(m_valid && m_tx != 0){
            m_TurretPID.SetReference(getTurretRotations() ,rev::ControlType::kPosition, 0);
    }
    else{
        printf("NO VISION TARGETS");
        // m_TurretPID.SetReference(leftTurretEndPoint,rev::ControlType::kPosition, 0);
        // m_TurretPID.SetReference(rightTurretEndPoint,rev::ControlType::kPosition, 0);
    }

}

// void subsystem_Turret::swingTurretAround() {
//     if(m_valid && m_tx < 0){
//         whichEndPoint = false;
//         m_TurretPID.SetReference(rightTurretEndPoint, rev::ControlType::kPosition, 0);
//     }
//     if(m_valid && m_tx > 0){
//         whichEndPoint = true;
//         m_TurretPID.SetReference(leftTurretEndPoint, rev::ControlType::kPosition, 0);
//     }
// }

void subsystem_Turret::hoodTest(){
    if(hoodTestPosition <= 13 && hoodTestPosition >= 0){
        m_HoodPID.SetReference(hoodTestPosition, rev::ControlType::kPosition);
    }
}

void subsystem_Turret::shootTest(){
    if(shooterTestPercent <= 100 && shooterTestPercent >= 0){
        m_FlywheelMotor1.Set(ControlMode::PercentOutput, shooterTestPercent);
    }
}

void subsystem_Turret::setHoodAngle() {
    // m_HoodPID.SetReference(findExitAngle(), rev::ControlType::kPosition, 0);
    // m_degrees = std::clamp(degrees, hoodEndPoint, ShooterConstants::topOfHood) *  ShooterConstants::kHood;
    // m_HoodPID.SetReference(m_degrees, rev::ControlType::kPosition, 0);
    if(xDistanceLimelightToGoal >= 252){
        if(xDistanceLimelightToGoal >= 240){
            if(xDistanceLimelightToGoal >= 228){
                if(xDistanceLimelightToGoal >= 216){
                    if(xDistanceLimelightToGoal >= 204){
                        if(xDistanceLimelightToGoal >= 192){
                            if(xDistanceLimelightToGoal >= 180){
                                if(xDistanceLimelightToGoal >= 168){
                                    if(xDistanceLimelightToGoal >= 156){
                                        if(xDistanceLimelightToGoal >= 144){
                                            if(xDistanceLimelightToGoal >= 132){
                                                if(xDistanceLimelightToGoal >= 120){
                                                    if(xDistanceLimelightToGoal >= 108){
                                                        if(xDistanceLimelightToGoal >= 96){
                                                            if(xDistanceLimelightToGoal >= 84){
                                                                if(xDistanceLimelightToGoal >= 72){
                                                                    if(xDistanceLimelightToGoal >= 60){ 
                                                                        //5 feet and closer
                                                                        m_degrees = (0.0) * xDistanceLimelightToGoal + 0.0;
                                                                        m_shooterPercent = (0.0) * xDistanceLimelightToGoal + 0.0;
                                                                        m_HoodPID.SetReference(m_degrees, rev::ControlType::kPosition);
                                                                    }
                                                                // 6 ft to 5 ft
                                                                m_degrees = (0.0) * xDistanceLimelightToGoal + 0.0;
                                                                m_shooterPercent = (0.0) * xDistanceLimelightToGoal + 0.0;
                                                                m_HoodPID.SetReference(m_degrees, rev::ControlType::kPosition);    
                                                                }
                                                            //7 ft to 6 ft
                                                            m_degrees = (0.0) * xDistanceLimelightToGoal + 0.0;
                                                            m_shooterPercent = (0.0) * xDistanceLimelightToGoal + 0.0;
                                                            m_HoodPID.SetReference(m_degrees, rev::ControlType::kPosition);
                                                            }
                                                        //8 ft to 7 ft
                                                        m_degrees = (0.0) * xDistanceLimelightToGoal + 0.0;
                                                        m_shooterPercent = (0.0) * xDistanceLimelightToGoal + 0.0;
                                                        m_HoodPID.SetReference(m_degrees, rev::ControlType::kPosition); 
                                                        }
                                                    //9 ft to 8 ft
                                                    m_degrees = (0.0) * xDistanceLimelightToGoal + 0.0;
                                                    m_shooterPercent = (0.0) * xDistanceLimelightToGoal + 0.0;
                                                    m_HoodPID.SetReference(m_degrees, rev::ControlType::kPosition);                                                        
                                                    }
                                                //10 ft to 9 ft
                                                m_degrees = (0.0) * xDistanceLimelightToGoal + 0.0;
                                                m_shooterPercent = (0.0) * xDistanceLimelightToGoal + 0.0;
                                                m_HoodPID.SetReference(m_degrees, rev::ControlType::kPosition);
                                                }
                                            //11 ft to 10 ft
                                            m_degrees = (0.0) * xDistanceLimelightToGoal + 0.0;
                                            m_shooterPercent = (0.0) * xDistanceLimelightToGoal + 0.0;
                                            m_HoodPID.SetReference(m_degrees, rev::ControlType::kPosition);   
                                            }
                                        //12 ft to 11 ft
                                        m_degrees = (0.0) * xDistanceLimelightToGoal + 0.0;
                                        m_shooterPercent = (0.0) * xDistanceLimelightToGoal + 0.0;
                                        m_HoodPID.SetReference(m_degrees, rev::ControlType::kPosition);
                                        }
                                    //13 ft to 12 ft
                                    m_degrees = (0.0) * xDistanceLimelightToGoal + 0.0;
                                    m_shooterPercent = (0.0) * xDistanceLimelightToGoal + 0.0;
                                    m_HoodPID.SetReference(m_degrees, rev::ControlType::kPosition);    
                                    }
                                //14 ft to 13 ft
                                m_degrees = (0.0) * xDistanceLimelightToGoal + 0.0;
                                m_shooterPercent = (0.0) * xDistanceLimelightToGoal + 0.0;
                                m_HoodPID.SetReference(m_degrees, rev::ControlType::kPosition);    
                                }
                            //15 ft to 14 ft
                            m_degrees = (0.0) * xDistanceLimelightToGoal + 0.0;
                            m_shooterPercent = (0.0) * xDistanceLimelightToGoal + 0.0;
                            m_HoodPID.SetReference(m_degrees, rev::ControlType::kPosition);    
                            }
                        //16 ft to 15 ft
                        m_degrees = (0.0) * xDistanceLimelightToGoal + 0.0;
                        m_shooterPercent = (0.0) * xDistanceLimelightToGoal + 0.0;
                        m_HoodPID.SetReference(m_degrees, rev::ControlType::kPosition);    
                        }
                    //17 ft to 16 ft
                    m_degrees = (0.0) * xDistanceLimelightToGoal + 0.0;
                    m_shooterPercent = (0.0) * xDistanceLimelightToGoal + 0.0;
                    m_HoodPID.SetReference(m_degrees, rev::ControlType::kPosition);    
                    }
                //18 ft to 17 ft
                m_degrees = (0.0) * xDistanceLimelightToGoal + 0.0;
                m_shooterPercent = (0.0) * xDistanceLimelightToGoal + 0.0;
                m_HoodPID.SetReference(m_degrees, rev::ControlType::kPosition);
                }
            //19 ft to 18 ft
            m_degrees = (0.0) * xDistanceLimelightToGoal + 0.0;
            m_shooterPercent = (0.0) * xDistanceLimelightToGoal + 0.0;
            m_HoodPID.SetReference(m_degrees, rev::ControlType::kPosition);    
            }
        //20 ft to 19 ft
        m_degrees = (0.0) * xDistanceLimelightToGoal + 0.0;
        m_shooterPercent = (0.0) * xDistanceLimelightToGoal + 0.0;
        m_HoodPID.SetReference(m_degrees, rev::ControlType::kPosition);
        }
    //21 ft to 20 ft
    m_degrees = (0.0) * xDistanceLimelightToGoal + 0.0;
    m_shooterPercent = (0.0) * xDistanceLimelightToGoal + 0.0;
    m_HoodPID.SetReference(m_degrees, rev::ControlType::kPosition);
    }

}

void subsystem_Turret::startShootAtExitVelocity() {
    m_FlywheelMotor1.Set(ControlMode::PercentOutput, m_shooterPercent);
}

void subsystem_Turret::shootAlternate() {
    m_TurretPID.SetReference(leftTurretEndPoint,rev::ControlType::kPosition, 0);
    m_FlywheelMotor1.Set(ControlMode::Velocity, ShooterConstants::weeeeeeeeee);

}

void subsystem_Turret::endShooter() {
    m_shooterPercent = 0.0;
	m_FlywheelMotor1.Set(ControlMode::PercentOutput, m_shooterPercent);
}

double subsystem_Turret::findExitAngle(){
    // exitAngle = atan((tan(ShooterConstants::desiredLandingAngle) * xDistanceLimelightToGoal - (2 * deltaHeight))/(-deltaHeight));
    // exitAngle *= ShooterConstants::kA; 
    exitAngle = atan(deltaHeight / xDistanceLimelightToGoal) * ShooterConstants::kA;
    return exitAngle;
}

double subsystem_Turret::getTurretRotations(){
    m_rotation = ShooterConstants::kRotations * m_tx; 
    // if(m_rotation > leftTurretEndPoint && m_rotation < rightTurretEndPoint){
        return m_rotation;
    // } 

}

// void subsystem_Turret::calibrateLeftEndPoint(){
//     while(!leftLimitSensor.Get()){
//         m_TurretPID.SetReference(-0.1, rev::ControlType::kVelocity, 0);
//     }
//     if(leftLimitSensor.Get()){
//         leftTurretEndPoint = m_TurretEncoder.GetPosition(); 
//     }
// }

// void subsystem_Turret::calibrateRightEndPoint(){
//     while(!rightLimitSensor.Get()){
//         m_TurretPID.SetReference(0.1, rev::ControlType::kVelocity, 0);
//     }
//     if(rightLimitSensor.Get()){
//         rightTurretEndPoint = m_TurretEncoder.GetPosition(); 
//     }
// }

void subsystem_Turret::calibrateHoodEndPoint(){
    while(!hoodLimitSensor.Get()){
        m_HoodPID.SetReference(-0.1, rev::ControlType::kVelocity, 0);
    }
    if(hoodLimitSensor.Get()){
        hoodEndPoint = m_HoodEncoder.GetPosition();
    }
}

double subsystem_Turret::getHoodPosition(){
    return m_HoodEncoder.GetPosition();
}

// double subsystem_Turret::getLeftEndPoint(){
//     return leftTurretEndPoint;
// }

// double subsystem_Turret::getRightEndPoint(){
//     return rightTurretEndPoint;
// }

bool subsystem_Turret::canSeeTarget(){
    return m_valid;
}

bool subsystem_Turret::setLight(bool on){
    lightOn = on; 
    m_table_ptr->PutNumber("ledMode", on ? 0 : 1);
}

void subsystem_Turret::toggleLight(){
    lightOn = !lightOn;
    setLight(lightOn);
}

// bool subsystem_Turret::isAtOppositeEndPoint(){
//     if(fabs(m_TurretEncoder.GetPosition() - rightTurretEndPoint) > 5 && !whichEndPoint){
//         return false;
//     }
//     if(fabs(m_TurretEncoder.GetPosition() - leftTurretEndPoint) > 5 && whichEndPoint){
//         return false;
//     }
//     return true;
// }

double subsystem_Turret::getTurretPosition(){
    double pos = m_TurretEncoder.GetPosition();
    return pos;
}


double subsystem_Turret::getDistanceToGoal(){
    xDistanceLimelightToGoal = (deltaHeight)/tan(angleToGoalRadians); 
    return xDistanceLimelightToGoal;
}

double subsystem_Turret::getTargetSpeed(){
    return m_TargetSpeed;
}

double subsystem_Turret::getActualSpeed(){
    return m_ActualSpeed;
}

double subsystem_Turret::getShootSpeed(){
    return m_shooterPercent;
}
bool subsystem_Turret::isFlyWheelRunning(){
    return m_TargetSpeed > 0;
}

bool subsystem_Turret::isAtTargetRPM(){
    return fabs(m_TargetSpeed - m_ActualSpeed) < ShooterConstants::kRPMTolerance;
}

double subsystem_Turret::rpmToVelocity(double rpm){
    return (ShooterConstants::kFlywheelCPR /* encoder ticks per revolution */ * rpm) / (600.0 /* 100ms per minute */);
}

double subsystem_Turret::rpmToVelocity(units::angular_velocity::revolutions_per_minute_t rpm) {
	return rpmToVelocity(units::angular_velocity::revolutions_per_minute_t(rpm).value());
}


double subsystem_Turret::velocityToRPM(double velocity){
    return (600.0 /* 100ms per minute */ * velocity) / (ShooterConstants::kFlywheelCPR /* encoder ticks per revolution */);
}

double subsystem_Turret::getPercentOutput(){
    return m_FlywheelMotor1.GetMotorOutputPercent();
}

void subsystem_Turret::checkTurretCenter(){
    if(leftHallEffect.Get() && rightHallEffect.Get()){
        centerPosition = m_TurretEncoder.GetPosition();
    }
    rightTurretEndPoint = centerPosition + ShooterConstants::rotationsCenterToLimit;
    leftTurretEndPoint = centerPosition - ShooterConstants::rotationsCenterToLimit;
}

// This method will be called once per scheduler run
void subsystem_Turret::Periodic() {
    checkTurretCenter();
    m_ActualSpeed = m_FlywheelFilter.Calculate(velocityToRPM(m_FlywheelMotor1.GetSelectedSensorVelocity(0)));

    // these are a bunch of values from the limelight network table, i dont use all of them i just like to have them handy :D
    m_valid = (m_table_ptr->GetNumber("tv", 0.0) > 0);
    m_tx = m_table_ptr->GetNumber("tx", 0.0);
    m_ty = m_table_ptr->GetNumber("ty", 0.0);
    m_ta = m_table_ptr->GetNumber("ta", 0.0);
    m_ts = m_table_ptr->GetNumber("ts", 0.0);
    m_tl = m_table_ptr->GetNumber("tl", 0.0);

    m_tshort = m_table_ptr->GetNumber("tshort", 0.0);
    m_tlong = m_table_ptr->GetNumber("tlong", 0.0);
    m_thor = m_table_ptr->GetNumber("thor", 0.0);
    m_tvert = m_table_ptr->GetNumber("tvert", 0.0);
    m_getpipe = m_table_ptr->GetNumber("tgetpipe", 0.0);
    m_camtran = m_table_ptr->GetNumber("camtran", 0.0);

    // hoodTestPosition = frc::SmartDashboard::GetNumber("Hood Position (1-12)", 0);
    // shooterTestPercent = frc::SmartDashboard::GetNumber("Flywheel Percent", 0.0);

    // distance from the target to the floor
    angleToGoalDegrees = ShooterConstants::limelightMountAngleDegrees + m_ty;
    angleToGoalRadians = angleToGoalDegrees * (3.14159 / 180.0);

    // mShuffleboardReady.SetBoolean(isFlyWheelRunning() && (fabs(m_TargetSpeed - m_ActualSpeed) < 75.0));
	// mShuffleboardActualRPM.SetDouble(m_ActualSpeed);
	// mShuffleboardActualPercent.SetDouble(getPercentOutput());
	// m_BoostPercent = mShuffleboardBoost.GetDouble(m_BoostPercent);

    //calculate distance
    //calculate exit angle & velocity https://www.desmos.com/calculator/lazkfsymei
}
