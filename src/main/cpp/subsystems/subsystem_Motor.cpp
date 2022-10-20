// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/subsystem_Motor.h"
#include "frc/smartdashboard/SmartDashboard.h"

subsystem_Motor::subsystem_Motor(): m_motor{15, rev::CANSparkMaxLowLevel::MotorType::kBrushless} {}

// This method will be called once per scheduler run
void subsystem_Motor::Periodic() {}

void subsystem_Motor::setPercentOutput(double percentOutput){
    frc::SmartDashboard::PutNumber("Unset: ", m_motor.Get());
    m_motor.Set(percentOutput);
    frc::SmartDashboard::PutNumber("Set: ", m_motor.Get());
}
