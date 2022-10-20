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

namespace IndexerConstants {
    constexpr int indexerID = 15;
    constexpr int breakerPort0 = 0;
    constexpr int breakerPort1 = 1;
    constexpr int breakerPort2 = 2;
    constexpr double percentOutput = 0.5;
    constexpr int xboxRightDPad = 11;

    constexpr int xboxA = 1;
    constexpr int xboxB = 2;
    constexpr int xboxX = 3;
    constexpr int xboxY = 4;
}

namespace ShooterConstants {

  const int hoodID = 1;
  const int flywheelID = 2;
  const int turretID = 0;


  const  double gravity = -9.806;
  const int kTimeoutMs = 30;
  
  const double kHoodD = 0.0; // Derivative gain
  const double kHoodF = 0.046503; // Feed forward gain
  const double kHoodI = 0.0; // Integral gain
  const double kHoodP = 0.22; // Proportional gain

  const double kAimP = 0.1;
  const double kAimI = 0.1;
  const double kAimD = 0.0;

  constexpr static double kR = 0.02469136; 
  constexpr static double kT = 0.03703704;
  constexpr static double kA = 0.02469136; 
  constexpr static double kV = 0.0;

  constexpr static double weeeeeeeeee = 0.0;

   // how many degrees back is your limelight rotated from perfectly vertical?
  constexpr double limelightMountAngleDegrees = 25.0;

  // distance from the center of the Limelight lens to the floor
  constexpr double limelightLensHeightInches = 20.0;

  // distance from the target to the floor
  constexpr double goalHeightInches = 60.0;

  constexpr double desiredLandingAngle = -69.0;
}