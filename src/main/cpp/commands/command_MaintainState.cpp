// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_MaintainState.h"
#include "subsystems/subsystem_Indexer.h"

command_MaintainState::command_MaintainState(subsystem_Indexer* indexer): 
                                            m_indexer{indexer}{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({indexer});
}

// Called when the command is initially scheduled.
void command_MaintainState::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_MaintainState::Execute() {
  m_indexer->setState();
  switch(m_indexer->getState()){
    case 1:
      if(!m_indexer->isBeam0Broken()){
        m_indexer->setPercentOutput(0.0);
      }
      if(m_indexer->isBeam0Broken()){
        m_indexer->setPercentOutput(0.5);
        pico::ColorSensor::RawColor color0 = m_indexer->getColor0();
      }
      if(m_indexer->isBeam2Broken()){
        pico::ColorSensor::RawColor color2 = m_indexer->getColor2();
        //Send color data to motor
      }
      break;
    
    case 2:
      if(!m_indexer->isBeam2Broken()){
        m_indexer->setPercentOutput(0.5);
      }
      if(m_indexer->isBeam1Broken() && m_indexer->isBeam2Broken()){
        m_indexer->setPercentOutput(0.0);
      }
      if(m_indexer->isBeam0Broken() && m_indexer->isBeam2Broken()){
          m_indexer->getColor0();
          m_indexer->getColor2();
          //Send color data to shooter motor
      }
      break;
    
    case 3:
      if(!m_indexer->isMotorFast()){
        m_indexer->setPercentOutput(-0.5);
        break;
      } else {
        m_indexer->setPercentOutput(0.5);
        break;
      }    
    default:
      m_indexer->setPercentOutput(0.0);
      break;
  }
}

// Called once the command ends or is interrupted.
void command_MaintainState::End(bool interrupted) {
  m_indexer->setPercentOutput(0.0);
}

// Returns true when the command should end.
bool command_MaintainState::IsFinished() {
  bool failed = m_indexer->getChannel0() == NULL || m_indexer->getChannel1() == NULL || m_indexer->getChannel2() == NULL;
  return failed;
}
