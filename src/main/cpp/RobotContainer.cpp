// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() : m_AimToTargetWithLimelight(&m_turret), m_shoot(&m_turret) {

  m_turret.SetDefaultCommand(command_AimToTargetWithLimelight(&m_turret));
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
     frc2::JoystickButton xboxA(&controller, ControllerConstants::xboxA);
     frc2::JoystickButton xboxB(&controller, ControllerConstants::xboxB);

     xboxA.WhenPressed(command_shoot(&m_turret));
     xboxB.WhenPressed(command_endShoot(&m_turret));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_AimToTargetWithLimelight;
}
