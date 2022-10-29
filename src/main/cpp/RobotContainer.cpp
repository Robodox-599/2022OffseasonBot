// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem), m_picoC{&m_picoS}, m_motorC{&m_motorS, &m_breakersS, m_direction}, m_direction{}, m_breakersC{&m_breakersS, &m_motorS, &m_picoS} {
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

  frc2::POVButton xboxPOVUp(&XboxYaperator, 0, 0);
  frc2::POVButton xboxPOVRight(&XboxYaperator, 90, 0);
  frc2::POVButton xboxPOVDown(&XboxYaperator, 180, 0);
  frc2::POVButton xboxPOVLeft(&XboxYaperator, 270, 0);
  frc2::JoystickButton xboxStart(&XboxYaperator, 8);

  // xboxStart.WhenPressed(command_Pico(&m_picoS));
  xboxPOVLeft.WhenPressed(command_Motor(&m_motorS, &m_breakersS, [=]{return 0;}));
  xboxPOVDown.WhenPressed(command_Motor(&m_motorS, &m_breakersS, [=]{return -1;}));
  xboxPOVUp.WhenPressed(command_Motor(&m_motorS, &m_breakersS, [=]{return 1;}));
  xboxPOVRight.WhenPressed(command_Motor(&m_motorS, &m_breakersS, [=]{return 2;}));
  xboxStart.WhenPressed(command_Breakers(&m_breakersS, &m_motorS, &m_picoS));
  // xboxStart.WhenPressed(command_Pico(&m_picoS));

  xboxLB.WhenPressed( command_ZeroGyro(&m_Drive) );

  
  xboxRB.WhenPressed(command_IntakeMode(&m_intake));

}


// right button on a toggle left trigger in right trigger out




frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
