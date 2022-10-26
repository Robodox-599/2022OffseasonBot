// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/subsystem_Breakers.h"
#include "frc/smartdashboard/SmartDashboard.h"

subsystem_Breakers::subsystem_Breakers(): m_breaker0{0}, m_breaker1{2}, m_breaker2{4} {}

// This method will be called once per scheduler run
void subsystem_Breakers::Periodic() {}

bool subsystem_Breakers::isBeam0Broken(){
    return m_breaker0.Get();
}

bool subsystem_Breakers::isBeam1Broken(){
    return m_breaker1.Get();
}

bool subsystem_Breakers::isBeam2Broken(){
    return m_breaker2.Get();
}

int subsystem_Breakers::getChannel0(){
    return m_breaker0.GetChannel();
}

int subsystem_Breakers::getChannel1(){
    return m_breaker1.GetChannel();
}

int subsystem_Breakers::getChannel2(){
    return m_breaker2.GetChannel();
}

void subsystem_Breakers::print(){

    frc::SmartDashboard::PutBoolean("sensor 0 broken: ", isBeam0Broken());
    frc::SmartDashboard::PutBoolean("sensor 1 broken: ", isBeam1Broken());
    frc::SmartDashboard::PutBoolean("sensor 2 broken: ", isBeam2Broken());
    // frc::SmartDashboard::PutNumber("channel 0: ", getChannel0());
    // frc::SmartDashboard::PutNumber("channel 1: ", getChannel1());
    // frc::SmartDashboard::PutNumber("channel 2: ", getChannel2());
    
}
