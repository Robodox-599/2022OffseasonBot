// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/SmartDashboard/SmartDashboard.h>
#include "rev/CANSparkMax.h"
#include "ctre/Phoenix.h"
#include "Constants.h"

class subsystem_Climb : public frc2::SubsystemBase {
 public:
  subsystem_Climb();
  void SetRightClimbArmPosition(int ticks);
  void SetLeftClimbArmPosition(int ticks);
  double GetRightClimbArmPosition();
  double GetLeftClimbArmPosition();
  void HomingClimbArmSpeed();
  void SetClimbArmSpeedtoZero();
  void SetClimbArmForHoming();
  double GetRightClimbArmCurrent();
  double GetLeftClimbArmCurrent();
  //double GetRoll();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
 rev::CANSparkMax m_leftWinchMotor; 
 rev::CANSparkMax m_rightWinchMotor;
 rev::SparkMaxRelativeEncoder m_leftClimbEncoder;
 rev::SparkMaxRelativeEncoder m_rightClimbEncoder;
 rev::SparkMaxPIDController m_rightPidController; 
 rev::SparkMaxPIDController m_leftPidController;
//ctre::phoenix::sensors::WPI_Pigeon2 m_pidgey; 
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
