// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_Pico.h"
#include "subsystems/subsystem_Pico.h"
#include "frc/smartdashboard/SmartDashboard.h"

command_Pico::command_Pico(subsystem_Pico *pico): m_pico{pico} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_pico);
}

// Called when the command is initially scheduled.
void command_Pico::Initialize() {
  frc::SmartDashboard::PutString("", "init");
  // m_pico->sensor0Connected();
  // m_pico->getProximity0();
}

// Called repeatedly when this Command is scheduled to run
void command_Pico::Execute() {
  
  frc::SmartDashboard::PutString("Printing: ","printed");
  m_pico->print();
  // m_pico->sensor0Connected();
  // frc::SmartDashboard::PutNumber("Proximity 0 (cmd): %lu\n", (unsigned long) m_pico->getProximity0());
  
  
}
// Called once the command ends or is interrupted.
void command_Pico::End(bool interrupted) {}

// Returns true when the command should end.
bool command_Pico::IsFinished() {
  return false;
}
