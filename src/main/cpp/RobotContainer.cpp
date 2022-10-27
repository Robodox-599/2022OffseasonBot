// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
// m_maintainState{&m_indexer}, m_manual{&m_indexer, m_direction},
#include "frc/smartdashboard/SmartDashboard.h"
#include <frc2/command/button/POVButton.h>
#include "frc2/command/button/JoystickButton.h"
#include "RobotContainer.h"
#include "Constants.h"

RobotContainer::RobotContainer(): /*m_maintainState{&m_indexer, m_manual}, m_manual{}*/  m_picoC{&m_picoS}, m_motorC{&m_motorS, m_direction}, m_direction{}, m_breakersC{&m_breakersS, &m_motorS, &m_picoS}  {
  // Initialize all of your commands and subsystems here
  // m_maintainState.SetDefaultCommand(command_Manual(&m_indexer, [=]{return 0;}));
  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  frc::SmartDashboard::PutString("configure status: ", "configured");
  frc2::POVButton xboxPOVUp(&m_xbox, 0, 0);
  frc2::POVButton xboxPOVDown(&m_xbox, 180, 0);
  frc2::POVButton xboxPOVLeft(&m_xbox, 270, 0);
  frc2::JoystickButton xboxStart(&m_xbox, 8);
  frc2::JoystickButton xboxA(&m_xbox, IndexerConstants::xboxA);
  frc2::JoystickButton xboxB(&m_xbox, IndexerConstants::xboxB);
  frc2::JoystickButton xboxX(&m_xbox, IndexerConstants::xboxX);
  frc2::JoystickButton xboxY(&m_xbox, IndexerConstants::xboxY);
  // xboxStart.WhenPressed(command_Pico(&m_picoS));
  xboxPOVLeft.WhenPressed(command_Motor(&m_motorS, [=]{return 0;}));
  xboxPOVDown.WhenPressed(command_Motor(&m_motorS, [=]{return -1;}));
  xboxPOVUp.WhenPressed(command_Motor(&m_motorS, [=]{return 1;}));
  xboxStart.WhenPressed(command_Breakers(&m_breakersS, &m_motorS, &m_picoS));
  // xboxStart.WhenPressed(command_Pico(&m_picoS));
  // xboxPOVDown.WhenHeld(command_Manual(&m_indexer, [=]{return 1;}));
  // xboxStart.WhenPressed(command_MaintainState(&m_indexer, [=]{return 1;}));

  
  
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_picoC;
}
