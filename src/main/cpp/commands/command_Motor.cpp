// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_Motor.h"
#include "subsystems/subsystem_Motor.h"
#include "frc/smartdashboard/SmartDashboard.h"

command_Motor::command_Motor(subsystem_Motor *motor,  std::function<double()> PercentOutput): m_motor{motor}, m_PercentOutput{PercentOutput} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_motor);
}

// Called when the command is initially scheduled.
void command_Motor::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_Motor::Execute() {
  m_motor->setPercentOutput(m_PercentOutput());
  }


// Called once the command ends or is interrupted.
void command_Motor::End(bool interrupted) {}

// Returns true when the command should end.
bool command_Motor::IsFinished() {
  return true;
}

