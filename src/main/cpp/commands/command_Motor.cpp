// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_Motor.h"
#include "subsystems/subsystem_Motor.h"
#include "frc/smartdashboard/SmartDashboard.h"

command_Motor::command_Motor(subsystem_Motor *motor, subsystem_Breakers* breakers, std::function<int()> direction): m_motor{motor}, m_breakers{breakers}, m_direction{direction} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_motor);
  AddRequirements(m_breakers);
}

// Called when the command is initially scheduled.
void command_Motor::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_Motor::Execute() {
  double percentOutput = m_direction() == -1 ? -0.2 : m_direction() == 0 ? 0 : 0.2;
  if(m_direction() == 2){
    m_motor->setPercentOutput(percentOutput);
  } else { 
    if(m_direction() == -1){
      m_motor->setPercentOutput(percentOutput);
    } else {
      frc::SmartDashboard::PutString("motor configured: ", "configured");
      frc::SmartDashboard::PutNumber("direction: ", m_direction());
      frc::SmartDashboard::PutNumber("precentOutput: ", percentOutput);
      if(!m_breakers->isBeam2Broken()){
        m_motor->setPercentOutput(0.0);
      } else {
        m_motor->setPercentOutput(percentOutput);
      }
    }
  }
}

// Called once the command ends or is interrupted.
void command_Motor::End(bool interrupted) {}

// Returns true when the command should end.
bool command_Motor::IsFinished() {
  return false;
}

