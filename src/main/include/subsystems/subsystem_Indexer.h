// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "rev/CANSparkMax.h"
#include "PicoColorSensor.h"
#include "subsystems/subsystem_Limelight.h"
#include "frc/DigitalInput.h"
#include "frc/smartdashboard/SmartDashboard.h"

class subsystem_Indexer : public frc2::SubsystemBase {
 public:
  subsystem_Indexer();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  double getPercentOutput();
  void setPercentOutput(double speed);
  bool isBeam0Broken();
  bool isBeam1Broken();
  bool isBeam2Broken();
  int getChannel0();
  int getChannel1();
  int getChannel2();
  bool sensor0Connected();
  bool sensor2Connected();
  pico::ColorSensor::RawColor getColor0();
  pico::ColorSensor::RawColor getColor2(); 
  int getState();
  void setState();
  bool isMotorFast();


  

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  subsystem_Limelight m_limelight;
  rev::CANSparkMax m_indexerMotor;
  pico::ColorSensor m_colorSensor;
  frc::DigitalInput m_beamBreaker0;
  frc::DigitalInput m_beamBreaker1;
  frc::DigitalInput m_beamBreaker2;  
};