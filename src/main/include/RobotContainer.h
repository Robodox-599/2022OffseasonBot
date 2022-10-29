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
