// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_ZeroGyro.h"

command_ZeroGyro::command_ZeroGyro(subsystem_SwerveDrive* SwerveDrive): m_SwerveDrive{SwerveDrive} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_SwerveDrive});
}

// Called when the command is initially scheduled.
void command_ZeroGyro::Initialize() {
  m_SwerveDrive->ZeroGyro();
}

// Called repeatedly when this Command is scheduled to run
void command_ZeroGyro::Execute() {}

// Called once the command ends or is interrupted.
void command_ZeroGyro::End(bool interrupted) {}

// Returns true when the command should end.
bool command_ZeroGyro::IsFinished() {
  return true;
}
