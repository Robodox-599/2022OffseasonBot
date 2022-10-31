// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_Timer.h"

command_Timer::command_Timer(double Seconds):m_Seconds{Seconds} {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void command_Timer::Initialize() {
  Timer.Stop();
  Timer.Reset();
  Timer.Start();
  
}

// Called repeatedly when this Command is scheduled to run
void command_Timer::Execute() {}

// Called once the command ends or is interrupted.
void command_Timer::End(bool interrupted) {}

// Returns true when the command should end.
bool command_Timer::IsFinished() {
  return Timer.Get() >= units::second_t{m_Seconds};
}
