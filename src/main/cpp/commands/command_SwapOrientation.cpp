// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_SwapOrientation.h"

command_SwapOrientation::command_SwapOrientation(subsystem_SwerveDrive* SwerveDrive): m_SwerveDrive{SwerveDrive} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_SwerveDrive});
}

// Called when the command is initially scheduled.
void command_SwapOrientation::Initialize() {
  m_SwerveDrive->SwapOrientation();
}

// Called repeatedly when this Command is scheduled to run
void command_SwapOrientation::Execute() {}

// Called once the command ends or is interrupted.
void command_SwapOrientation::End(bool interrupted) {}

// Returns true when the command should end.
bool command_SwapOrientation::IsFinished() {
  return true;
}
