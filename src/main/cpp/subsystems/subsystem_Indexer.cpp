// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/subsystem_Indexer.h"
#include "Constants.h"
#include "frc/smartdashboard/SmartDashboard.h"

subsystem_Indexer::subsystem_Indexer(): m_limelight{}, m_indexerMotor{IndexerConstants::indexerID, rev::CANSparkMax::MotorType::kBrushless}, m_colorSensor{}, m_beamBreaker0{0}, m_beamBreaker1{1}, m_beamBreaker2{2} {}

// This method will be called once per scheduler run
void subsystem_Indexer::Periodic() {}

int state = 0;

double subsystem_Indexer::getPercentOutput(){
    return m_indexerMotor.Get();
}

void subsystem_Indexer::setPercentOutput(double speed){
    m_indexerMotor.Set(speed);
    /*
    Change percentOutput by state
    *Check doc for full explanation*
    */
}

bool subsystem_Indexer::isBeam0Broken(){
    return m_beamBreaker0.Get();
}

bool subsystem_Indexer::isBeam1Broken(){
    return m_beamBreaker1.Get();
}

bool subsystem_Indexer::isBeam2Broken(){
    return m_beamBreaker2.Get();
}

int subsystem_Indexer::getChannel0(){
    frc::SmartDashboard::PutBoolean("Breaker 0 Connected: \n", true /*m_beamBreaker0.GetChannel() == NULL*/);
    return m_beamBreaker0.GetChannel();
}

int subsystem_Indexer::getChannel1(){
    frc::SmartDashboard::PutBoolean("Breaker 1 Connected: \n", true /*m_beamBreaker1.GetChannel() == NULL*/);
    return m_beamBreaker1.GetChannel();
}

int subsystem_Indexer::getChannel2(){
    frc::SmartDashboard::PutBoolean("Breaker 2 Connected: \n", true /*m_beamBreaker2.GetChannel() == NULL*/);
    return m_beamBreaker2.GetChannel();
}

bool subsystem_Indexer::sensor0Connected(){
    frc::SmartDashboard::PutBoolean("Sensor 0 Connected: \n", m_colorSensor.IsSensor0Connected());
    return m_colorSensor.IsSensor0Connected();
}

bool subsystem_Indexer::sensor2Connected(){
    frc::SmartDashboard::PutBoolean("Sensor 2 Connected: \n", m_colorSensor.IsSensor2Connected());
    return m_colorSensor.IsSensor2Connected();
}

pico::ColorSensor::RawColor subsystem_Indexer::getColor0(){
    return m_colorSensor.GetRawColor0();
}

pico::ColorSensor::RawColor subsystem_Indexer::getColor2(){
    return m_colorSensor.GetRawColor2();
}

int subsystem_Indexer::getState(){
    return state;
}

void subsystem_Indexer::setState(){
    bool b0 = isBeam0Broken();
    bool b1 = isBeam1Broken();
    bool b2 = isBeam2Broken();

    if((b0 && !b1 && !b2) || (!b0 && b1 && !b2) || (!b0 && !b1 && b2)){
        state = 1;
    }
    if((b0 && b1 && !b2) || (!b0 && b1 && b2) || (b0 && !b1 && b2)){
        state = 2;
    }
    if(b0 && b1 && b2){
        state = 3;
    }
    if(!b0 && !b1 && !b2){
        state = 0;
    }
}

bool subsystem_Indexer::isMotorFast(){
    return m_limelight.getPercentOutput() >= m_limelight.findExitVelocity();
}