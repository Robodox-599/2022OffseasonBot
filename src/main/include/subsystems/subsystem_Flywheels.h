// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/TalonFX.h>
#include "Constants.h"

class subsystem_Flywheels : public frc2::SubsystemBase {
 public:
  subsystem_Flywheels();
  void setPercentOutput(double percentOutput);
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
 ctre::phoenix::motorcontrol::can::TalonFX m_Flywheel1;
 //ctre::phoenix::motorcontrol::can::TalonFC m_Flywheel2;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
