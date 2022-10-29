// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_TurretAndHoodCalibration.h"

command_TurretAndHoodCalibration::command_TurretAndHoodCalibration(subsystem_Turret *turret) : m_turret(turret) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_turret);
}

// Called when the command is initially scheduled.
void command_TurretAndHoodCalibration::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_TurretAndHoodCalibration::Execute() {
  // m_turret->getLeftEndPoint(); m_turret->getRightEndPoint(); m_turret->calibrateHoodEndPoint();
  }

// Called once the command ends or is interrupted.
void command_TurretAndHoodCalibration::End(bool interrupted) {}

// Returns true when the command should end.
bool command_TurretAndHoodCalibration::IsFinished() {
  return false;
}
