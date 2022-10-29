// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */
namespace ShooterConstants {

  const int hoodID = 0;
  const int flywheel1ID = 0;
  const int flywheel2ID = 5;
  const int turretID = 1;

  const double topOfHood = 0.0;

  const double rotationsCenterToLimit = 0.0;

  const double gravity = -9.806;
  const int kTimeoutMs = 30;
  
  const double kHoodD = 0.0; // Derivative gain
  const double kHoodI = 0.0; // Integral gain
  const double kHoodP = 0.07; // Proportional gain

  const double kFlywheelP = 0.1;
  const double kFlywheelI = 0.0;
  const double kFlywheelD = 0.0;
  const double kFlywheelF = 0.3; 

  const double kAimP = 0.15;
  const double kAimI = 0.0;
  const double kAimD = 0.0;

  constexpr static double kRotations = 0.02469136; 
  constexpr static double kHood = 0.03703704;
  constexpr static double kA = 0.02469136; 

  constexpr static double kV = 0.06;

  constexpr double kMaxRpm = 6380;
  const double kRPMTolerance = 200.0;
  const double kFlywheelGearRatio = 16 / 24;
	const double kFlywheelCPR = 2048 /* Falcon CPR */ * kFlywheelGearRatio;

  constexpr static double weeeeeeeeee = 0.0;

   // how many degrees back is your limelight rotated from perfectly vertical?
  constexpr double limelightMountAngleDegrees = 59.0;

  // distance from the center of the Limelight lens to the floor
  constexpr double limelightLensHeightInches = 46.6;

  // distance from the target to the floor
  constexpr double goalHeightInches = 60.0;

  constexpr double desiredLandingAngle = -69.0;
}

namespace ControllerConstants
{
    constexpr int xboxPort = 0;

    constexpr int xboxLXAxis = 0;
    constexpr int xboxLYAxis = 1;
    constexpr int xboxRXAxis = 4;
    constexpr int xboxRYAxis = 5;

    constexpr int xboxLTAxis = 2;
    constexpr int xboxRTAxis = 3;

    constexpr int xboxA = 1;
    constexpr int xboxB = 2;
    constexpr int xboxX = 3;
    constexpr int xboxY = 4;
    constexpr int xboxLB = 5;
    constexpr int xboxRB = 6;
    constexpr int xboxView = 7;
    constexpr int xboxMenu = 8;
    constexpr int xboxLeftJoyPress = 9;
    constexpr int xboxRightJoyPress = 10;
    
    constexpr int xboxRightDPad = 11;
}
