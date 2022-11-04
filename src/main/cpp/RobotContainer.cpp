// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem){
  // Initialize all of your commands and subsystems here


  m_Drive.SetDefaultCommand( command_SwerveDriveTeleop(&m_Drive,
                                                       [this]{return XboxDrive.GetRawAxis(ControllerConstants::xboxLYAxis);},
                                                       [this]{return XboxDrive.GetRawAxis(ControllerConstants::xboxLXAxis);},
                                                       [this]{return XboxDrive.GetRawAxis(ControllerConstants::xboxRXAxis);},
                                                       [this]{return SwerveConstants::IsFieldRelative;},
                                                       [this]{return SwerveConstants::IsOpenLoop;}));
   m_intake.SetDefaultCommand(command_IntakeRun(&m_intake, [this] {return XboxDrive.GetRawAxis(ControllerConstants::xboxRTAxis) - XboxDrive.GetRawAxis(ControllerConstants::xboxLTAxis); } ));
  // m_turret.SetDefaultCommand(command_AimToTargetWithLimelight(&m_turret));

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
   frc2::JoystickButton xboxA(&XboxYaperator, ControllerConstants::xboxA);
   frc2::JoystickButton xboxB(&XboxYaperator, ControllerConstants::xboxB);
   frc2::JoystickButton xboxX(&XboxYaperator, ControllerConstants::xboxX);
   frc2::JoystickButton xboxY(&XboxYaperator, ControllerConstants::xboxY);
   frc2::JoystickButton xboxRB(&XboxDriveBttns, ControllerConstants::xboxRB);
   frc2::JoystickButton xboxYDrive(&XboxDriveBttns, ControllerConstants::xboxY);
   frc2::JoystickButton xboxLBYaperator(&XboxYaperator, ControllerConstants::xboxLB);
   frc2::JoystickButton xboxRBYaperator(&XboxYaperator, ControllerConstants::xboxRB);
   frc2::JoystickButton xboxLB(&XboxDriveBttns, ControllerConstants::xboxLB);
   frc2::JoystickButton xboxLTAxis(&XboxYaperator, ControllerConstants::xboxLTAxis);
   frc2::JoystickButton xboxRTAxis(&XboxYaperator, ControllerConstants::xboxRTAxis);


  // // xboxStart.WhenPressed(command_Pico(&m_picoS));
   xboxY.WhenPressed(command_Motor(&m_motorS, [=]{return 0.0;}));
   xboxLBYaperator.WhenPressed(command_Motor(&m_motorS, [=]{return -0.4;}));
   xboxRBYaperator.WhenPressed(command_Motor(&m_motorS, [=]{return 0.4;}));
  // // xboxStart.WhenPressed(command_Breakers(&m_breakersS, &m_motorS, &m_picoS));
  // // // xboxStart.WhenPressed(command_Pico(&m_picoS));

  

   xboxYDrive.WhenPressed( command_ZeroGyro(&m_Drive) );
   xboxRB.WhenPressed(command_IntakeMode(&m_intake));
   xboxLB.WhenPressed( command_SwapOrientation(&m_Drive));
   xboxA.WhenPressed(command_shoot(&m_turret));
   xboxB.WhenPressed(command_endShoot(&m_turret));



}


// right button on a toggle left trigger in right trigger out




frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
