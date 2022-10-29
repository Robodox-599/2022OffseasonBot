<<<<<<< HEAD
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandScheduler.h>

#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"

#include "commands/command_ZeroGyro.h"
#include "commands/command_SwerveDriveTeleop.h"
#include "subsystems/subsystem_SwerveDrive.h"

#include "frc/XboxController.h"
#include "frc2/command/button/JoystickButton.h"
#include <frc/Joystick.h>
#include "Constants.h"
#include <frc/Joystick.h>

#include "subsystems/subsystem_Intake.h"
#include "commands/command_IntakeRun.h"
#include "commands/command_IntakeMode.h"

#include "commands/command_Pico.h"
#include "commands/command_Motor.h"
#include "commands/command_Breakers.h"
#include <frc/GenericHID.h>
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
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;

  subsystem_SwerveDrive m_Drive;
  subsystem_Intake m_intake;

  command_Pico m_picoC;
  subsystem_Pico m_picoS;
  
  command_Motor m_motorC;
  subsystem_Motor m_motorS;
  std::function<int()> m_direction;
  
  command_Breakers m_breakersC;
  subsystem_Breakers m_breakersS;

  frc::XboxController XboxDrive{ControllerConstants::XboxDriveID};
  frc::Joystick XboxDriveBttns{ControllerConstants::XboxDriveID};
  frc::Joystick XboxYaperator{ControllerConstants::XboxYaperatorID};


  void ConfigureButtonBindings();
};




=======
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include "frc/XboxController.h"
#include "frc2/command/button/JoystickButton.h"
#include "commands/command_shoot.h"
#include "commands/command_endShoot.h"
#include "subsystems/subsystem_Turret.h"
#include "commands/command_AimToTargetWithLimelight.h"
#include "commands/command_TurretAndHoodCalibration.h"

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

 private:
  // The robot's subsystems and commands are defined here...;
  frc::XboxController controller{0};

  subsystem_Turret m_turret; 

  command_AimToTargetWithLimelight m_AimToTargetWithLimelight;

  command_shoot m_shoot;

  void ConfigureButtonBindings();
};
>>>>>>> 830c8a3b024988a2022382f75788fd1b8d545366
