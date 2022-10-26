// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "Constants.h"
#include "rev/CANSparkMax.h"
#include "frc/DoubleSolenoid.h"


class subsystem_Intake : public frc2::SubsystemBase {
 public:
  subsystem_Intake();

  void setSpeed(double speed);
  void setIntakeDown();
  void setIntakeUp();
  bool isIntakeDeployed();
  void setIntakeWheelsOn(double outputPower);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:

 rev::CANSparkMax m_roller_motor;
 frc::DoubleSolenoid m_solenoid_left;
 frc::DoubleSolenoid m_solenoid_right;

 bool m_isIntakeDeployed;
 bool m_isExtended;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
