// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_LeftClimbByPositionRetract.h"

command_LeftClimbByPositionRetract::command_LeftClimbByPositionRetract(subsystem_Climb *Climb): m_Climb{Climb} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({Climb});
}

// Called when the command is initially scheduled.
void command_LeftClimbByPositionRetract::Initialize() {
  m_Climb->SetLeftClimbArmPosition(ClimbConstants::LeftClimbTicksDown);
}

// Called repeatedly when this Command is scheduled to run
void command_LeftClimbByPositionRetract::Execute() {}

// Called once the command ends or is interrupted.
void command_LeftClimbByPositionRetract::End(bool interrupted) {}

// Returns true when the command should end.
bool command_LeftClimbByPositionRetract::IsFinished() {
  return true;
}
