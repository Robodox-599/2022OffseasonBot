// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/subsystem_Indexer.h"

subsystem_Indexer::subsystem_Indexer(): m_breaker0{0}, m_breaker1{2}, m_breaker2{4}, m_motor{15, rev::CANSparkMaxLowLevel::MotorType::kBrushless}, m_pico{} {}

// This method will be called once per scheduler run
void subsystem_Indexer::Periodic() {}

bool subsystem_Indexer::isBeam0Broken(){return m_breaker0.Get();}

bool subsystem_Indexer::isBeam1Broken(){return m_breaker1.Get();}

bool subsystem_Indexer::isBeam2Broken(){return m_breaker2.Get();}

int subsystem_Indexer::getChannel0(){return m_breaker0.GetChannel();}

int subsystem_Indexer::getChannel1(){return m_breaker1.GetChannel();}

int subsystem_Indexer::getChannel2(){return m_breaker2.GetChannel();}

void subsystem_Indexer::setPercentOutput(double percentOutput){m_motor.Set(percentOutput);}

bool subsystem_Indexer::sensor0Connected(){
    
    return m_pico.IsSensor0Connected();
}

bool subsystem_Indexer::sensor2Connected(){
    
    return m_pico.IsSensor2Connected();
}

pico::ColorSensor::RawColor subsystem_Indexer::getColor0(){
    return m_pico.GetRawColor0();
}

pico::ColorSensor::RawColor subsystem_Indexer::getColor2(){
    return m_pico.GetRawColor2();
}

uint32_t subsystem_Indexer::getProximity0(){
    
    return m_pico.GetProximity0();
    
}

uint32_t subsystem_Indexer::getProximity2(){

    return m_pico.GetProximity2();
}

bool subsystem_Indexer::isRed(){
    return getColor2().red > getColor2().blue;
}

bool subsystem_Indexer::isBlue(){
    return getColor0().red < getColor0().blue;
}