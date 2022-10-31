// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_AimToTargetWithLimelight.h"

command_AimToTargetWithLimelight::command_AimToTargetWithLimelight(subsystem_Turret *turret) : m_turret(turret) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_turret);            
}

// Called when the command is initially scheduled.
void command_AimToTargetWithLimelight::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_AimToTargetWithLimelight::Execute() {
  // m_turret->aimAtTarget();
  // m_turret->setHoodAngle(); 
  //m_turret->hoodTest();
}

// Called once the command ends or is interrupted.
void command_AimToTargetWithLimelight::End(bool interrupted) {}

// Returns true when the command should end.
bool command_AimToTargetWithLimelight::IsFinished() {
  return false;
}
