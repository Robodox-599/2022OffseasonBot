// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_endShoot.h"

command_endShoot::command_endShoot(subsystem_Turret *shooter) : m_shooter{shooter} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_shooter});
}

// Called when the command is initially scheduled.
void command_endShoot::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_endShoot::Execute() {
  m_shooter->shootTest(0.0);
  frc::SmartDashboard::PutNumber("Hood Position", m_shooter->getHoodPosition());
}

// Called once the command ends or is interrupted.
void command_endShoot::End(bool interrupted) {}

// Returns true when the command should end.
bool command_endShoot::IsFinished() {
  return false;
}
