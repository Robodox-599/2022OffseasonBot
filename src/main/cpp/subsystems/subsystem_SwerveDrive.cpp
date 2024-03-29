
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.


#include "subsystems/subsystem_SwerveDrive.h"
#include "frc/smartdashboard/SmartDashboard.h"



subsystem_SwerveDrive::subsystem_SwerveDrive():m_Gyro{SwerveConstants::CANCoderID,  "DriveCANivore"}, 
                                               m_FrontLeftModule{FrontLeftModule::Constants},
                                               m_FrontRightModule{FrontRightModule::Constants},
                                               m_BackLeftModule{BackLeftModule::Constants},
                                               m_BackRightModule{BackRightModule::Constants},
                                               m_Odometry{SwerveConstants::m_kinematics, m_Gyro.GetRotation2d()}
{
    m_Gyro.ConfigFactoryDefault();
    ZeroGyro();


}

void subsystem_SwerveDrive::SwerveDrive(units::meters_per_second_t xSpeed,
                                        units::meters_per_second_t ySpeed,
                                        units::radians_per_second_t zRot,
                                        bool FieldRelative, 
                                        bool IsOpenLoop){
    auto moduleStates = SwerveConstants::m_kinematics.ToSwerveModuleStates(
        FieldRelative ? frc::ChassisSpeeds::FromFieldRelativeSpeeds(
                            xSpeed, ySpeed, zRot, GetYaw()
                        ): frc::ChassisSpeeds{xSpeed, ySpeed, zRot});
    SwerveConstants::m_kinematics.DesaturateWheelSpeeds(&moduleStates, SwerveConstants::MaxSpeed);
    auto [FrontLeft, FrontRight, BackLeft, BackRight] = moduleStates;
    //auto [FrontRight, RearRight,]

     m_FrontLeftModule.SetDesiredState(FrontLeft, IsOpenLoop);
    m_FrontRightModule.SetDesiredState(FrontRight, IsOpenLoop);
     m_BackLeftModule.SetDesiredState(BackLeft, IsOpenLoop);
    m_BackRightModule.SetDesiredState(BackRight, IsOpenLoop);

    frc::SmartDashboard::SmartDashboard::PutNumber("Front Left Angle", FrontLeft.angle.Degrees().value() );
    frc::SmartDashboard::SmartDashboard::PutNumber("Front Left Drive", FrontLeft.speed.value() );    

    frc::SmartDashboard::SmartDashboard::PutNumber("Front Right Angle", FrontRight.angle.Degrees().value() );
    frc::SmartDashboard::SmartDashboard::PutNumber("Front Right Drive", FrontRight.speed.value() );
    
    frc::SmartDashboard::SmartDashboard::PutNumber("Back Left Angle", BackLeft.angle.Degrees().value() );
    frc::SmartDashboard::SmartDashboard::PutNumber("Back Left Drive", BackLeft.speed.value() );

    frc::SmartDashboard::SmartDashboard::PutNumber("Back Right Angle", BackRight.angle.Degrees().value() );
    frc::SmartDashboard::SmartDashboard::PutNumber("Back Right Drive", BackRight.speed.value() );
}

void subsystem_SwerveDrive::SetModuleStates(wpi::array<frc::SwerveModuleState, 4> desiredStates){
  SwerveConstants::m_kinematics.DesaturateWheelSpeeds(&desiredStates,
                                         AutoConstants::MaxSpeed);
  m_FrontLeftModule.SetDesiredState(desiredStates[0], false);
  m_FrontRightModule.SetDesiredState(desiredStates[1], false);
  m_BackLeftModule.SetDesiredState(desiredStates[2], false);
  m_BackRightModule.SetDesiredState(desiredStates[3], false);
}

void subsystem_SwerveDrive::SwapOrientation(){
    m_FrontLeftModule.SwapOrientation();
}



void subsystem_SwerveDrive::ResetOdometry(frc::Pose2d Pose){
    m_Odometry.ResetPosition(Pose, m_Gyro.GetRotation2d());
}

frc::Pose2d subsystem_SwerveDrive::GetPose(){
    return m_Odometry.GetPose();
}

frc::Rotation2d subsystem_SwerveDrive::GetYaw(){
    
    units::degree_t Yaw{ m_Gyro.GetYaw() };
    return (SwerveConstants::InvertGyro) ? frc::Rotation2d{360_deg - Yaw}: frc::Rotation2d{Yaw}; 
}



void subsystem_SwerveDrive::ZeroGyro(){
    m_Gyro.SetYaw(0);
}



// This method will be called once per scheduler run
void subsystem_SwerveDrive::Periodic() {



    m_Odometry.Update(m_Gyro.GetRotation2d(),
                      m_FrontLeftModule.GetState(),
                      m_FrontRightModule.GetState(),
                      m_BackLeftModule.GetState(),
                      m_BackRightModule.GetState() );

}

