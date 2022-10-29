// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_SwingTurretAround.h"

command_SwingTurretAround::command_SwingTurretAround(subsystem_Turret *turret) : m_turret(turret) {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void command_SwingTurretAround::Initialize() {
  // if(m_turret->getLeftEndPoint() || m_turret->getRightEndPoint()){
  //   m_turret->swingTurretAround();
  // }
}

// Called repeatedly when this Command is scheduled to run
void command_SwingTurretAround::Execute() {}

// Called once the command ends or is interrupted.
void command_SwingTurretAround::End(bool interrupted) {}

// Returns true when the command should end.
bool command_SwingTurretAround::IsFinished() {}
