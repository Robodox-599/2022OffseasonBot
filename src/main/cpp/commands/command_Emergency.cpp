// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_Emergency.h"
#include "subsystems/subsystem_Indexer.h"

command_Emergency::command_Emergency(subsystem_Indexer* indexer): 
                                      m_indexer{indexer} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({indexer});
}

// Called when the command is initially scheduled.
void command_Emergency::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_Emergency::Execute() {
  m_indexer->setPercentOutput(0.5);
  bool breaker0 = m_indexer->getChannel0() == NULL;
  bool breaker1 = m_indexer->getChannel1() == NULL;
  bool breaker2 = m_indexer->getChannel2() == NULL;
  bool breakers[3] = {breaker0, breaker1, breaker2};
  int breakersFailed = 0;
  for(int i = 0; i < 3; i++){
    if(breakers[i]){
      breakersFailed++;
    }
  }
  switch(breakersFailed){
    case 1:
      if(breaker0){
        
        if(m_indexer->isBeam1Broken()){
          m_indexer->setPercentOutput(0.0);
        }
      }
      break;
    default:
      break;
  }
}

// Called once the command ends or is interrupted.
void command_Emergency::End(bool interrupted) {}

// Returns true when the command should end.
bool command_Emergency::IsFinished() {
  return false;
}
