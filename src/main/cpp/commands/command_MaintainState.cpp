// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_MaintainState.h"

command_MaintainState::command_MaintainState() {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void command_MaintainState::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_MaintainState::Execute() {}

// Called once the command ends or is interrupted.
void command_MaintainState::End(bool interrupted) {}

// Returns true when the command should end.
bool command_MaintainState::IsFinished() {
  return false;
}
