// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandScheduler.h>
// #include "commands/command_MaintainState.h"
// #include "commands/command_Manual.h"
#include "commands/command_Pico.h"
#include "commands/command_Motor.h"
#include "commands/command_Breakers.h"
#include <frc/GenericHID.h>
// #include "subsystems/subsystem_Indexer.h"
#include "frc/XboxController.h"
#include "frc2/command/button/JoystickButton.h"
#include <frc/Joystick.h>
#include <frc2/command/button/POVButton.h>

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();
  void switchCommand();

 private:
  // The robot's subsystems and commands are defined here...
  // subsystem_Indexer m_indexer;
  // command_MaintainState m_maintainState;
  // command_Manual m_manual;
  std::function<int()> m_direction;
  frc::XboxController m_xbox{0};
  command_Pico m_picoC;
  subsystem_Pico m_picoS;
  command_Motor m_motorC;
  subsystem_Motor m_motorS;
  command_Breakers m_breakersC;
  subsystem_Breakers m_breakersS;
  // frc2::Command::Command;
  // frc::GenericHID m_hid{3};
  

  void ConfigureButtonBindings();
  
};
