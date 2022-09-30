// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_Manual.h"
#include "subsystems/subsystem_Indexer.h"

command_Manual::command_Manual(subsystem_Indexer* indexer, std::function<int()> direction): m_indexer{indexer}, m_direction{direction} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({indexer});
}

// Called when the command is initially scheduled.
void command_Manual::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_Manual::Execute() {
  
  if(m_direction() == 0){
    m_indexer->setPercentOutput(0.5);
  }
  if(m_direction() == 1){
    m_indexer->setPercentOutput(-0.5);
  }
}

// Called once the command ends or is interrupted.
void command_Manual::End(bool interrupted) {
  m_indexer->setPercentOutput(0.0);
}

// Returns true when the command should end.
bool command_Manual::IsFinished() {
  return false;
}
