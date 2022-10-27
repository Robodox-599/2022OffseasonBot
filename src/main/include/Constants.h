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
namespace ClimbConstants 
{
//Climb Ports
    //Will Replace this when I find out which ports the Climb Will be
    constexpr int leftWinchMotorPort = 0;
    constexpr int rightWinchMotorPort = 0;
    constexpr int pigeon = 0;

//Climb Current
    //Need to test what the ClimbCurrentSpike would be
    constexpr int ClimbCurrentSpike = 0;
    constexpr int HomingPercentOutput = 0;
    constexpr bool RightWinchMotor = true;
    constexpr bool LeftWinchMotor = false;

//Climb Measurements
    //Have to test what value the ticks need to 
    //be for the climb arm to be at the very top and bottom
    constexpr int LeftClimbTicksUp = 0;
    constexpr int LeftClimbTicksDown = 0;
    constexpr int LeftClimbPartialTicks = 0; 
    constexpr int RightClimbTicksUp = 0; 
    constexpr int RightClimbTicksDown = 0; 
    constexpr int RightClimbPartialTicks = 0; 
    constexpr int RightPartialClimbTicks = 0;
    constexpr int kHighBarExtendAngle = 0;
    constexpr int kHighBarContactAngle = 0;
    constexpr int kTraversalBarExtendAngle = 0;
    constexpr int kTraversalBarContactAngle = 0;

//Climb PID Constants
    constexpr int kP = 0;
    constexpr int kI = 0;
    constexpr int kD = 0; 
    constexpr int kIz = 0;
    constexpr int kFF = 0;
    constexpr int kMaxOutput = 1;
    constexpr int kMinOutput = -1;
}

namespace ControllerConstants
{
    constexpr int xboxPort = 0;
    constexpr int xboxA = 1;
    constexpr int xboxB = 2;
}