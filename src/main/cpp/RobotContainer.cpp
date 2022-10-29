// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here

  m_Drive.SetDefaultCommand( command_SwerveDriveTeleop(&m_Drive,
                                                       [this]{return XboxDrive.GetRawAxis(ControllerConstants::xboxLYAxis);},
                                                       [this]{return XboxDrive.GetRawAxis(ControllerConstants::xboxLXAxis);},
                                                       [this]{return XboxDrive.GetRawAxis(ControllerConstants::xboxRXAxis);},
                                                       [this]{return SwerveConstants::IsFieldRelative;},
                                                       [this]{return SwerveConstants::IsOpenLoop;}));
  m_intake.SetDefaultCommand(command_IntakeRun(&m_intake, [this] {return XboxDrive.GetRawAxis(ControllerConstants::xboxLTAxis) - XboxDrive.GetRawAxis(ControllerConstants::xboxRTAxis); } ));
  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
   frc2::JoystickButton xboxA(&XboxYaperator, ControllerConstants::xboxA);
   frc2::JoystickButton xboxB(&XboxYaperator, ControllerConstants::xboxB);
   frc2::JoystickButton xboxX(&XboxYaperator, ControllerConstants::xboxX);
   frc2::JoystickButton xboxY(&XboxYaperator, ControllerConstants::xboxY);
   frc2::JoystickButton xboxRB(&XboxYaperator, ControllerConstants::xboxRB);
   frc2::JoystickButton xboxLB(&XboxDriveBttns, ControllerConstants::xboxLB);
   frc2::JoystickButton xboxLTAxis(&XboxYaperator, ControllerConstants::xboxLTAxis);
   frc2::JoystickButton xboxRTAxis(&XboxYaperator, ControllerConstants::xboxRTAxis);

  xboxLB.WhenPressed( command_ZeroGyro(&m_Drive) );

  
  xboxRB.WhenPressed(command_IntakeMode(&m_intake));

}


// right button on a toggle left trigger in right trigger out




frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
