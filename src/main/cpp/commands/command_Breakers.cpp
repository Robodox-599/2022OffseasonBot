// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_Breakers.h"

command_Breakers::command_Breakers(subsystem_Breakers* breakers, subsystem_Motor* motor, subsystem_Pico* pico): m_breakers{breakers}, m_motor{motor}, m_pico{pico} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_breakers);
  AddRequirements(m_motor);
  AddRequirements(m_pico);
}

// Called when the command is initially scheduled.
void command_Breakers::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_Breakers::Execute() {
  m_breakers->print();
  if(!m_breakers->isBeam0Broken() && !m_breakers->isBeam1Broken() && !m_breakers->isBeam2Broken() && m_pico->isRed()){
    m_motor->setPercentOutput(0.5);
  } else {
    m_motor->setPercentOutput(0.0);
  }
}

// Called once the command ends or is interrupted.
void command_Breakers::End(bool interrupted) {}

// Returns true when the command should end.
bool command_Breakers::IsFinished() {
  return false;
}
