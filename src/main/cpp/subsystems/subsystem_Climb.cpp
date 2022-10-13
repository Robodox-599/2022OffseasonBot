// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/subsystem_Climb.h"

subsystem_Climb::subsystem_Climb() :
m_leftWinchMotor{0,rev::CANSparkMax::MotorType::kBrushless},
m_rightWinchMotor{0,rev::CANSparkMax::MotorType::kBrushless},
m_leftClimbEncoder{m_leftWinchMotor.GetEncoder()},
m_rightClimbEncoder{m_rightWinchMotor.GetEncoder()},
m_leftPidController(m_leftWinchMotor.GetPIDController()),
m_rightPidController(m_rightWinchMotor.GetPIDController())

{
double kP = 0, kI = 0, kD = 0, kIz = 0, kFF = 0, kMaxOutput = 1, kMinOutput = -1;
  //leftWinchMotor
  m_leftClimbEncoder.SetPosition(0);
  m_leftPidController.SetP(kP);
  m_leftPidController.SetI(kI);
  m_leftPidController.SetD(kD);
  m_leftPidController.SetIZone(kIz);
  m_leftPidController.SetFF(kFF);
  m_leftPidController.SetOutputRange(kMinOutput, kMaxOutput);

  //rightWinchMotor
  m_rightClimbEncoder.SetPosition(0);
  m_rightPidController.SetP(kP);
  m_rightPidController.SetI(kI);
  m_rightPidController.SetD(kD);
  m_rightPidController.SetIZone(kIz);
  m_rightPidController.SetFF(kFF);
  m_rightPidController.SetOutputRange(kMinOutput, kMaxOutput);
} 

void subsystem_Climb::SetRightClimbArmPosition(int ticks)
{
  m_rightPidController.SetReference(ticks, rev::ControlType::kPosition, 0);

}

void subsystem_Climb::SetLeftClimbArmPosition(int ticks)
{
  m_leftPidController.SetReference(ticks, rev::ControlType::kPosition, 0);

}

double subsystem_Climb::GetClimbArmCurrent()
{
  return m_rightWinchMotor.GetOutputCurrent();
  return m_leftWinchMotor.GetOutputCurrent();
}

void subsystem_Climb::SetClimbArmSpeedForHoming()
{
  m_leftWinchMotor.Set(0.2);
  m_rightWinchMotor.Set(0.2);
}

void subsystem_Climb::SetClimbArmSpeedtoZero()
{
  m_leftWinchMotor.Set(0);
  m_rightWinchMotor.Set(0);
}


// This method will be called once per scheduler run

void subsystem_Climb::Periodic() {
frc::SmartDashboard::PutNumber("Left Encoder Position", m_leftClimbEncoder.GetPosition());
frc::SmartDashboard::PutNumber("Right Encoder Position", m_rightClimbEncoder.GetPosition());
/*frc::SmartDashboard::PutNumber("P Gain", kP);
frc::SmartDashboard::PutNumber("I Gain", kI);
frc::SmartDashboard::PutNumber("D Gain", kD);
frc::SmartDashboard::PutNumber("I Zone", kIz);
frc::SmartDashboard::PutNumber("Feed Forward", kFF);
frc::SmartDashboard::PutNumber("Max Output", kMaxOutput);
frc::SmartDashboard::PutNumber("Min Output", kMinOutput);*/
}
