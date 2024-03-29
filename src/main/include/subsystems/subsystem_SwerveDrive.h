// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "SwerveModule.h"
#include "Constants.h"
#include <vector>
#include <units/velocity.h>
#include <frc/kinematics/ChassisSpeeds.h>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <frc/kinematics/SwerveDriveOdometry.h>
#include <frc/kinematics/SwerveModuleState.h>
#include <frc/geometry/Pose2d.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/geometry/Translation2d.h>

#include <ctre/phoenix/sensors/WPI_Pigeon2.h>



class subsystem_SwerveDrive : public frc2::SubsystemBase {
 public:
  subsystem_SwerveDrive();
  void SwerveDrive(units::meters_per_second_t xSpeed,
                   units::meters_per_second_t ySpeed,
                   units::radians_per_second_t zRot,
                   bool FieldRelative, 
                   bool IsOpenLoop);
  void SwerveDrive(frc::Translation2d Translation, 
                  units::degrees_per_second_t Rotation,
                  bool FieldRelative, 
                  bool IsOpenLoop  );
  void SetModuleStates(wpi::array<frc::SwerveModuleState, 4> desiredStates);
  void SwapOrientation();

  
  void ZeroGyro();
  void ResetOdometry(frc::Pose2d Pose);
  frc::Pose2d GetPose();
  frc::Rotation2d GetYaw();


  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  
  ctre::phoenix::sensors::WPI_Pigeon2 m_Gyro;

  SwerveModule m_FrontLeftModule;
  SwerveModule m_FrontRightModule;
  SwerveModule m_BackLeftModule;
  SwerveModule m_BackRightModule;

  frc::SwerveDriveOdometry<4> m_Odometry;

  

  
  //std::vector<SwerveModule> m_Mods;
                           
  
};
