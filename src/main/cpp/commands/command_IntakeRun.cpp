// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_IntakeRun.h"
#include "subsystems/subsystem_Intake.h"

command_IntakeRun::command_IntakeRun(subsystem_Intake* intake, std::function<double()> outputPower): 
                                    m_intake{intake}, m_outputPower{outputPower}{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({intake});
}

// Called when the command is initially scheduled.
// left in right out right bumper toggle


void command_IntakeRun::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_IntakeRun::Execute() {

  if(m_intake->isIntakeDeployed())
  {
    m_intake->setIntakeWheelsOn(0.5 *m_outputPower());
    printf("Intake wheels on \n");
  }

}

// Called once the command ends or is interrupted.
void command_IntakeRun::End(bool interrupted) {}

// Returns true when the command should end.
bool command_IntakeRun::IsFinished() {
  return false;
}
