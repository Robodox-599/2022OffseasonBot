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
//m_pidgey{ClimbConstants::pigeon}

{
  //leftWinchMotor
  m_leftClimbEncoder.SetPosition(0);
  m_leftPidController.SetP(ClimbConstants::kP);
  m_leftPidController.SetI(ClimbConstants::kI);
  m_leftPidController.SetD(ClimbConstants::kD);
  m_leftPidController.SetIZone(ClimbConstants::kIz);
  m_leftPidController.SetFF(ClimbConstants::kFF);
  m_leftPidController.SetOutputRange(ClimbConstants::kMinOutput, ClimbConstants::kMaxOutput);

  //rightWinchMotor
  m_rightClimbEncoder.SetPosition(0);
  m_rightPidController.SetP(ClimbConstants::kP);
  m_rightPidController.SetI(ClimbConstants::kI);
  m_rightPidController.SetD(ClimbConstants::kD);
  m_rightPidController.SetIZone(ClimbConstants::kIz);
  m_rightPidController.SetFF(ClimbConstants::kFF);
  m_rightPidController.SetOutputRange(ClimbConstants::kMinOutput, ClimbConstants::kMaxOutput);
} 

void subsystem_Climb::SetRightClimbArmPosition(int ticks)
{m_rightPidController.SetReference(ticks, rev::ControlType::kPosition, 0);}

void subsystem_Climb::SetLeftClimbArmPosition(int ticks)
{m_leftPidController.SetReference(ticks, rev::ControlType::kPosition, 0);}

double subsystem_Climb::GetRightClimbArmCurrent()
{return m_rightWinchMotor.GetOutputCurrent();}

double subsystem_Climb::GetLeftClimbArmCurrent()
{return m_leftWinchMotor.GetOutputCurrent();}

void subsystem_Climb::SetClimbArmForHoming()
{m_leftWinchMotor.Set(ClimbConstants::HomingPercentOutput);
 m_rightWinchMotor.Set(ClimbConstants::HomingPercentOutput);}

void subsystem_Climb::SetClimbArmSpeedtoZero()
{m_leftWinchMotor.Set(0);
 m_rightWinchMotor.Set(0);}

double subsystem_Climb::GetLeftClimbArmPosition()
{m_leftClimbEncoder.GetPosition();}

double subsystem_Climb::GetRightClimbArmPosition()
{m_rightClimbEncoder.GetPosition();}

/*double subsystem_Climb::GetRoll()
{m_pidgey.GetRoll();}*/

// This method will be called once per scheduler run

void subsystem_Climb::Periodic() {
frc::SmartDashboard::PutNumber("Left Encoder Position", m_leftClimbEncoder.GetPosition());
frc::SmartDashboard::PutNumber("Right Encoder Position", m_rightClimbEncoder.GetPosition());
frc::SmartDashboard::PutNumber("P Gain", ClimbConstants::kP);
frc::SmartDashboard::PutNumber("I Gain", ClimbConstants::kI);
frc::SmartDashboard::PutNumber("D Gain", ClimbConstants::kD);
frc::SmartDashboard::PutNumber("I Zone", ClimbConstants::kIz);
frc::SmartDashboard::PutNumber("Feed Forward", ClimbConstants::kFF);
frc::SmartDashboard::PutNumber("Max Output", ClimbConstants::kMaxOutput);
frc::SmartDashboard::PutNumber("Min Output", ClimbConstants::kMinOutput);
}
