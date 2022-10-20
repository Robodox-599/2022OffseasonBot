// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
// look into "inline"
/*
Blue: SCL
White: SDA
Red: Power
Black: GND
*/
#include "subsystems/subsystem_Pico.h"
#include "frc/smartdashboard/SmartDashboard.h"

subsystem_Pico::subsystem_Pico(): m_colorSensor{} {}

// This method will be called once per scheduler run
void subsystem_Pico::Periodic() {}

bool subsystem_Pico::sensor0Connected(){
    
    return m_colorSensor.IsSensor0Connected();
}

bool subsystem_Pico::sensor2Connected(){
    
    return m_colorSensor.IsSensor2Connected();
}

pico::ColorSensor::RawColor subsystem_Pico::getColor0(){
    return m_colorSensor.GetRawColor0();
}

pico::ColorSensor::RawColor subsystem_Pico::getColor2(){
    return m_colorSensor.GetRawColor2();
}

uint32_t subsystem_Pico::getProximity0(){
    
    return m_colorSensor.GetProximity0();
    
}

uint32_t subsystem_Pico::getProximity2(){

    return m_colorSensor.GetProximity2();
}

bool subsystem_Pico::isRed(){
    return getColor2().red > getColor2().blue;
}

bool subsystem_Pico::isBlue(){
    return getColor0().red < getColor0().blue;
}

void subsystem_Pico::print(){
    uint32_t red0 = getColor0().red;
    uint32_t green0 = getColor0().green;
    uint32_t blue0 = getColor0().blue;
    frc::SmartDashboard::PutNumber("\nProximity 0: %lu\n", (unsigned long) getProximity0());
    frc::SmartDashboard::PutBoolean("\nsensor 0 connected\n", sensor0Connected());
    frc::SmartDashboard::PutNumber("\ncolor0, red\n", red0);
    frc::SmartDashboard::PutNumber("\ncolor0, green\n", green0);
    frc::SmartDashboard::PutNumber("\ncolor0, blue\n", blue0);
    frc::SmartDashboard::PutBoolean("\n0; Red > Blue and Red > Green\n", red0 > blue0);
    frc::SmartDashboard::PutBoolean("\n0; Blue > Red and Blue > Green\n", blue0 > red0);

    uint32_t red2 = getColor2().red;
    uint32_t green2 = getColor2().green;
    uint32_t blue2 = getColor2().blue;
    frc::SmartDashboard::PutBoolean("sensor 2 connected: ", m_colorSensor.IsSensor2Connected());
    frc::SmartDashboard::PutNumber("\nProximity 2: %lu\n", (unsigned long) getProximity2());
    frc::SmartDashboard::PutNumber("\ncolor2, red\n", red2);
    frc::SmartDashboard::PutNumber("\ncolor2, green\n", green2);
    frc::SmartDashboard::PutNumber("\ncolor2, blue\n", blue2);
    frc::SmartDashboard::PutBoolean("\n2; Red > Blue and Red > Green\n", red2 > blue2 && red2 > green2);
    frc::SmartDashboard::PutBoolean("\n2; Blue > Red and Blue > Green\n", blue2 > red2 && blue2 > green2);
}