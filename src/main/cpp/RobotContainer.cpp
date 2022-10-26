// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"


RobotContainer::RobotContainer() : m_autonomousCommand(&m_intake, [=]{return 0.0;}) 
{
  // Initialize all of your commands and subsystems here
  m_intake.SetDefaultCommand(command_IntakeRun(&m_intake, [this] {return xbox.GetRawAxis(ControllerConstants::xboxLTAxis) - xbox.GetRawAxis(ControllerConstants::xboxRTAxis); } ));
  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  frc2::JoystickButton xboxA(&xbox, ControllerConstants::xboxA);
  frc2::JoystickButton xboxB(&xbox, ControllerConstants::xboxB);
  frc2::JoystickButton xboxX(&xbox, ControllerConstants::xboxX);
  frc2::JoystickButton xboxY(&xbox, ControllerConstants::xboxY);
  frc2::JoystickButton xboxRB(&xbox, ControllerConstants::xboxRB);
  frc2::JoystickButton xboxLB(&xbox, ControllerConstants::xboxLB);
  frc2::JoystickButton xboxLT(&xbox, ControllerConstants::xboxLTAxis);
  frc2::JoystickButton atk3ArmUp(&atk3, ControllerConstants::atk3ArmUp);
  frc2::JoystickButton atk3ArmDown(&atk3, ControllerConstants::atk3ArmDown);
  frc2::JoystickButton atk3WinchUnlock(&atk3, ControllerConstants::atk3WinchUnlock);
  frc2::JoystickButton atk3WinchUp(&atk3, ControllerConstants::atk3WinchUp);
  frc2::JoystickButton atk3WinchDown(&atk3, ControllerConstants::atk3WinchDown);
  frc2::JoystickButton atk3TraverseLeft(&atk3, ControllerConstants::atk3TraverseLeft);
  frc2::JoystickButton atk3TraverseRight(&atk3, ControllerConstants::atk3TraverseRight);


  
xboxRB.WhenPressed(command_IntakeMode(&m_intake));

}


// right button on a toggle left trigger in right trigger out




frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
