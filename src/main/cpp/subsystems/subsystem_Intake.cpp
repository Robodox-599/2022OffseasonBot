// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the roosfehdfgisdfjhsdfjhosdfdfjhksdft directory of this project.

#include "subsystems/subsystem_Intake.h"


subsystem_Intake::subsystem_Intake():m_roller_motor{IntakeConstants::intakeMotorPort,rev::CANSparkMaxLowLevel::MotorType::kBrushless},
                                    m_solenoid_left{frc::PneumaticsModuleType::CTREPCM,IntakeConstants::intakePistonLA,IntakeConstants::intakePistonLB}, 
                                    m_solenoid_right{frc::PneumaticsModuleType::CTREPCM,IntakeConstants::intakePistonRA,IntakeConstants::intakePistonRB}{

}

void subsystem_Intake::setSpeed(double speed){

    m_roller_motor.Set(speed);

}

void subsystem_Intake::setIntakeUp()
{
    m_solenoid_right.Set(frc::DoubleSolenoid::kReverse);
    m_solenoid_left.Set(frc::DoubleSolenoid::kReverse);
    m_isExtended = false;
}

void subsystem_Intake::setIntakeDown()
{
    m_solenoid_right.Set(frc::DoubleSolenoid::kForward);
    m_solenoid_left.Set(frc::DoubleSolenoid::kForward);
    m_isExtended = true;
}

bool subsystem_Intake::isIntakeDeployed()
{
    return m_isExtended;
}



void subsystem_Intake::setIntakeWheelsOn(double outputPower){
    m_roller_motor.Set(outputPower);
}
// This method will be called once per scheduler run
void subsystem_Intake::Periodic() {}
