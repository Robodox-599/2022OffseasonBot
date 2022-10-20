// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "PicoColorSensor.h"


class subsystem_Pico : public frc2::SubsystemBase {
 public:
  subsystem_Pico();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  
  bool sensor0Connected();
  bool sensor2Connected();
  pico::ColorSensor::RawColor getColor0();
  pico::ColorSensor::RawColor getColor2();
  uint32_t getProximity0();
  uint32_t getProximity2();
  void print();
  bool isRed();
  bool isBlue();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  pico::ColorSensor m_colorSensor;
};
