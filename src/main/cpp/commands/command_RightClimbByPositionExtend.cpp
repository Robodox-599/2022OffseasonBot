// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_RightClimbByPositionExtend.h"

command_RightClimbByPositionExtend::command_RightClimbByPositionExtend(subsystem_Climb *Climb): m_Climb{Climb} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({Climb});
}

// Called when the command is initially scheduled.
void command_RightClimbByPositionExtend::Initialize() {
  m_Climb->SetRightClimbArmPosition(ClimbConstants::RightClimbTicksUp);
}

// Called repeatedly when this Command is scheduled to run
void command_RightClimbByPositionExtend::Execute() {}

// Called once the command ends or is interrupted.
void command_RightClimbByPositionExtend::End(bool interrupted) {}

// Returns true when the command should end.
bool command_RightClimbByPositionExtend::IsFinished() {
  return false;
}
