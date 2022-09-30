// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "frc/smartdashboard/SmartDashboard.h"
#include <frc2/command/button/POVButton.h>
#include "RobotContainer.h"
#include "Constants.h"

RobotContainer::RobotContainer(): m_maintainState{&m_indexer}, m_manual{&m_indexer, m_direction} {
  // Initialize all of your commands and subsystems here
  
  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  frc2::POVButton xboxPOVUp(&m_xbox, 0, 0);
  frc2::POVButton xboxPOVDown(&m_xbox, 0, 180);
  frc2::JoystickButton xboxStart(&m_xbox, 8);
  // xboxPOVUp.WhenHeld(command_Manual(&m_indexer, [=]{return 0;}));
  // xboxPOVDown.WhenHeld(command_Manual(&m_indexer, [=]{return 1;}));
  // xboxStart.WhenPressed(command_MaintainState(&m_indexer));

  
  
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_maintainState;
}
