// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "frc/DigitalInput.h"

class subsystem_Breakers: 
  public frc2::SubsystemBase {
    public:
      subsystem_Breakers();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
      void Periodic() override;

      bool isBeam0Broken();
      bool isBeam1Broken();
      bool isBeam2Broken();

      int getChannel0();
      int getChannel1();
      int getChannel2();

      void print();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  frc::DigitalInput m_breaker0;
  frc::DigitalInput m_breaker1;
  frc::DigitalInput m_breaker2;
};
