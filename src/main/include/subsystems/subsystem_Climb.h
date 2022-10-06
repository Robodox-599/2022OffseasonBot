// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "rev/CANSparkMax.h"
#include "Constants.h"

class subsystem_Climb : public frc2::SubsystemBase {
 public:
  subsystem_Climb();
  void ExtendRightClimb(int ticks);
  void RetractRightClimb(int ticks);
  void ExtendLeftClimb(int ticks);
  void RetractLeftClimb(int ticks);
  /*int GetRightClimbArmPosition();
  int GetLeftClimbArmPosition();*/
  
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
 bool m_IsEnabled;
 rev::CANSparkMax m_leftWinchMotor; 
 rev::CANSparkMax m_rightWinchMotor;
 rev::SparkMaxRelativeEncoder m_leftClimbEncoder;
 rev::SparkMaxRelativeEncoder m_rightClimbEncoder;
 rev::SparkMaxPIDController m_ClimbPidController; 


  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
