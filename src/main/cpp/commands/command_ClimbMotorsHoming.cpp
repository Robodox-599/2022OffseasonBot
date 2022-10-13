// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_ClimbMotorsHoming.h"

command_ClimbMotorsHoming::command_ClimbMotorsHoming(subsystem_Climb *Climb): m_Climb{Climb} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({Climb});
}

// Called when the command is initially scheduled.
void command_ClimbMotorsHoming::Initialize() {
m_Climb->SetClimbArmSpeedForHoming();
}
// Called repeatedly when this Command is scheduled to run
void command_ClimbMotorsHoming::Execute(){
  if(m_Climb->GetClimbArmCurrent() >= ClimbConstants::ClimbCurrentSpike){
    m_Climb->SetClimbArmSpeedtoZero(); 
  }
}

// Called once the command ends or is interrupted.
void command_ClimbMotorsHoming::End(bool interrupted) {}

// Returns true when the command should end.
bool command_ClimbMotorsHoming::IsFinished() {
  return false;
}
