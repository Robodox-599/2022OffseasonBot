// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/subsystem_Limelight.h"

subsystem_Limelight::subsystem_Limelight():
m_FlywheelMotor{ShooterConstants::flywheelID}, 
m_TurretMotor{ShooterConstants::turretID, rev::CANSparkMax::MotorType::kBrushless}, 
m_HoodMotor{ShooterConstants::hoodID, rev::CANSparkMax::MotorType::kBrushless},   
m_TurretEncoder{m_TurretMotor.GetEncoder()},
m_HoodEncoder{m_HoodMotor.GetEncoder()},
m_HoodPID{m_HoodMotor.GetPIDController()},
m_TurretPID{m_TurretMotor.GetPIDController()}
{
//shooter config
  m_FlywheelMotor.ConfigFactoryDefault();
    // m_FlywheelMotor.ConfigAllSettings(); bleh
    // m_FlywheelMotor.SetInverted();
  m_FlywheelMotor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);

//sensor config
  m_FlywheelMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, ShooterConstants::kTimeoutMs);
  m_FlywheelMotor.SetSensorPhase(true);
  m_FlywheelMotor.SetSelectedSensorPosition(0, 0, ShooterConstants::kTimeoutMs);

//closed loop gains
  m_FlywheelMotor.Config_kD(0, ShooterConstants::kHoodD, ShooterConstants::kTimeoutMs);
  m_FlywheelMotor.Config_kF(0, ShooterConstants::kHoodF, ShooterConstants::kTimeoutMs);
  m_FlywheelMotor.Config_kI(0, ShooterConstants::kHoodI, ShooterConstants::kTimeoutMs);
  m_FlywheelMotor.Config_kP(0, ShooterConstants::kHoodP, ShooterConstants::kTimeoutMs);
  m_FlywheelMotor.SelectProfileSlot(0, 0);

  m_HoodPID.SetP(ShooterConstants::kHoodP);
  m_HoodPID.SetI(ShooterConstants::kHoodI);
  m_HoodPID.SetD(ShooterConstants::kHoodD);

  m_TurretPID.SetP(ShooterConstants::kAimP);
  m_TurretPID.SetI(ShooterConstants::kAimI);
  m_TurretPID.SetD(ShooterConstants::kAimD);
}

void subsystem_Limelight::aimAtTarget() {
    if(m_valid && m_tx != 0){
            m_TurretPID.SetReference(getTurretRotations() ,rev::ControlType::kPosition, 0);
    }
    else{
        printf("NO VISION TARGETS");
        // m_TurretPID.SetReference(leftTurretEndPoint,rev::ControlType::kPosition, 0);
        // m_TurretPID.SetReference(rightTurretEndPoint,rev::ControlType::kPosition, 0);
    }
}

void subsystem_Limelight::adjustHoodByPosition() {
    // m_HoodPID.SetReference(findExitAngle(), rev::ControlType::kPosition, 0);
    if(m_valid){
        m_HoodPID.SetReference(findExitAngle(), rev::ControlType::kPosition);
        
    }
}

double subsystem_Limelight::getPercentOutput(){
    return m_FlywheelMotor.Get();
}

void subsystem_Limelight::startShootAtExitVelocity() {
    m_FlywheelMotor.Set(ControlMode::Velocity, findExitVelocity());
}

void subsystem_Limelight::shootAlternate() {
    m_TurretPID.SetReference(leftTurretEndPoint,rev::ControlType::kPosition, 0);
    m_FlywheelMotor.Set(ControlMode::Velocity, ShooterConstants::weeeeeeeeee);
}

void subsystem_Limelight::endShooter() {
    m_FlywheelMotor.Set(ControlMode::Velocity, 0.0);
}

double subsystem_Limelight::findExitVelocity(){
    exitVelocity = sqrt((ShooterConstants::gravity * (xDistanceLimelightToGoal * xDistanceLimelightToGoal) * (1 + (tan(exitAngle) * tan(exitAngle))))/((2 * deltaHeight) - (2 * xDistanceLimelightToGoal * tan(exitAngle))));
    exitVelocity *= ShooterConstants::kV;
    return exitVelocity;
}

double subsystem_Limelight::findExitAngle(){
    // exitAngle = atan((tan(ShooterConstants::desiredLandingAngle) * xDistanceLimelightToGoal - (2 * deltaHeight))/(-deltaHeight));
    // exitAngle *= ShooterConstants::kA; 
    exitAngle = m_ty * m_ta * ShooterConstants::kA;
    return exitAngle;
}

double subsystem_Limelight::getTurretRotations(){
    m_rotation = ShooterConstants::kR * m_tx; 
    return m_rotation;

}

void subsystem_Limelight::getLeftEndPoint(){
    while(!leftLimitSensor.Get()){
        m_TurretPID.SetReference(-0.1, rev::ControlType::kVelocity);
    }
    if(leftLimitSensor.Get()){
        leftTurretEndPoint = m_TurretEncoder.GetPosition(); 
    }
}

void subsystem_Limelight::getRightEndPoint(){
    while(!rightLimitSensor.Get()){
        m_TurretPID.SetReference(0.1, rev::ControlType::kVelocity);
    }
    if(rightLimitSensor.Get()){
        rightTurretEndPoint = m_TurretEncoder.GetPosition(); 
    }
}

void subsystem_Limelight::getHoodEndPoint(){
    while(!hoodLimitSensor.Get()){
        m_HoodPID.SetReference(-0.1, rev::ControlType::kVelocity);
    }
    if(hoodLimitSensor.Get()){
        hoodEndPoint = m_HoodEncoder.GetPosition();
    }
}

// This method will be called once per scheduler run
void subsystem_Limelight::Periodic() {

    printf("crunky wunky");

    hoodPosition = ShooterConstants::kA * exitAngle; 
    m_turn = ShooterConstants::kT * m_tx; 

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

    // distance from the target to the floor
    angleToGoalDegrees = ShooterConstants::limelightMountAngleDegrees + m_ty;
    angleToGoalRadians = angleToGoalDegrees * (3.14159 / 180.0);

    //calculate distance
    xDistanceLimelightToGoal = (ShooterConstants::goalHeightInches - ShooterConstants::limelightLensHeightInches)/tan(angleToGoalRadians); 

    //calculate exit angle & velocity https://www.desmos.com/calculator/lazkfsymei
}