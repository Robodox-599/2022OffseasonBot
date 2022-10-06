// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/subsystem_Climb.h"

subsystem_Climb::subsystem_Climb() :
m_leftWinchMotor{0,rev::CANSparkMax::MotorType::kBrushless},
m_rightWinchMotor{0,rev::CANSparkMax::MotorType::kBrushless},
m_leftClimbEncoder{m_leftWinchMotor.GetEncoder()},
m_rightClimbEncoder{m_rightWinchMotor.GetEncoder()},
m_ClimbPidController(m_leftWinchMotor.GetPIDController())
{
  //leftWinchMotor
  
  //rightWinchMotor
} 

/*Climb methods:
1. always start with setExtendForClimb() to prepare

2. use setClimbMidBar when only climbing to second rung

3. use this sequence for traveral climb steps
   - setClimbMidBarAndExtend() to climb mid rung with right climb and extend left climb
   - setClimbHighBarAndExtend() to climb high rung with left climb and extend right arm
   - setClimbTraversalBar() to climb partial distance with right climb on traversal bar
*/

//extending right arm to start Climb
void subsystem_Climb::ExtendRightClimb(int ticks)
{
  m_rightWinchMotor;
}

 
void subsystem_Climb::RetractRightClimb(int ticks)
{
  m_rightWinchMotor;
}

void subsystem_Climb::ExtendLeftClimb(int ticks)
{
  m_leftWinchMotor;
}

//Traversal second step
void subsystem_Climb::RetractLeftClimb(int ticks)
{
  m_leftWinchMotor;
}



// This method will be called once per scheduler run
void subsystem_Climb::Periodic() {}
