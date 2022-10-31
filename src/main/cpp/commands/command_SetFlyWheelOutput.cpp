// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_SetFlyWheelOutput.h"

command_SetFlyWheelOutput::command_SetFlyWheelOutput(subsystem_Flywheels* Flywheels): m_Flywheels{Flywheels} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_Flywheels});
}

// Called when the command is initially scheduled.
void command_SetFlyWheelOutput::Initialize() {
  m_Flywheels->setPercentOutput(0.20);
}

// Called repeatedly when this Command is scheduled to run
void command_SetFlyWheelOutput::Execute() {}

// Called once the command ends or is interrupted.
void command_SetFlyWheelOutput::End(bool interrupted) {}

// Returns true when the command should end.
bool command_SetFlyWheelOutput::IsFinished() {
  return false;
}
