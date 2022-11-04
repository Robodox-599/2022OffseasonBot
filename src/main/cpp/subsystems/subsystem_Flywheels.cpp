// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/subsystem_Flywheels.h"

subsystem_Flywheels::subsystem_Flywheels() :m_Flywheel1{ShooterConstants::flywheel1ID}{

}
void subsystem_Flywheels::setPercentOutput(double percentOutput){
    m_Flywheel1.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, percentOutput);
}

// This method will be called once per scheduler run
void subsystem_Flywheels::Periodic() {}
