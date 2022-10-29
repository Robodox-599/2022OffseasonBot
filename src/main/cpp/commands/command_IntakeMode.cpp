// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_IntakeMode.h"


command_IntakeMode::command_IntakeMode(subsystem_Intake* intake) : m_intake{intake} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({intake});
}

// Called when the command is initially scheduled.
void command_IntakeMode::Initialize() 
{
  printf("intake command \n");

  if(m_intake->isIntakeDeployed())
  {
    
    m_intake->setIntakeUp();
    printf("intake up \n");
  }
  else
  {
    m_intake->setIntakeDown();
        printf("intake down \n");

  }
  
}

// Called repeatedly when this Command is scheduled to run
void command_IntakeMode::Execute() {}

// Called once the command ends or is interrupted.
void command_IntakeMode::End(bool interrupted) {}

// Returns true when the command should end.
bool command_IntakeMode::IsFinished() { return true; }