// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_shoot.h"

// #define RAMP

command_shoot::command_shoot(subsystem_Turret *shooter) : m_shooter{shooter} {
  // Use addRequirements() here to declare subsystem dependencies.
    AddRequirements({m_shooter});
}

// Called when the command is initially scheduled.
void command_shoot::Initialize() {
	// m_shooter->startShootAtExitVelocity();
	m_shooter->shootTest();
	frc::SmartDashboard::PutNumber("Shoot Speed:", m_shooter->getShootSpeed());
}

// Called repeatedly when this Command is scheduled to run
void command_shoot::Execute() {



}

// Called once the command ends or is interrupted.
void command_shoot::End(bool interrupted) {}

// Returns true when the command should end.
bool command_shoot::IsFinished() {
  return m_shooter->isAtTargetRPM();
}
