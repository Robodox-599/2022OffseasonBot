// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <units/length.h>
#include <units/voltage.h>
#include <units/velocity.h>
#include <units/time.h>
#include <units/acceleration.h>
#include <units/angular_acceleration.h>

#include <frc/kinematics/SwerveDriveKinematics.h>
#include <frc/trajectory/TrapezoidProfile.h>




/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */
namespace ControllerConstants{
    constexpr double Deadband = 0.2;
    
    constexpr int XboxDriveID = 0;
    constexpr int XboxYaperatorID = 1;

    constexpr int xboxLXAxis = 0;
    constexpr int xboxLYAxis = 1;
    constexpr int xboxRXAxis = 4;
    constexpr int xboxRYAxis = 5;

    constexpr int xboxLTAxis = 2;
    constexpr int xboxRTAxis = 3;

    constexpr int xboxA = 1;
    constexpr int xboxB = 2;
    constexpr int xboxX = 3;
    constexpr int xboxY = 4;
    constexpr int xboxLB = 5;
    constexpr int xboxRB = 6;
    constexpr int xboxView = 7;
    constexpr int xboxMenu = 8;
    constexpr int xboxLeftJoyPress = 9;
    constexpr int xboxRightJoyPress = 10;
    constexpr int xboxRightDPad = 11;
}

namespace SwerveConstants{
    constexpr int CANCoderID = 12; 
    constexpr bool InvertGyro = true;

    /*Drivetrain constants*/
    constexpr double OpenLoopRamp = 0.25;
    constexpr double closedLoopRamp = 0.2;

    constexpr double DriveGearRatio = 6.75;
    constexpr double AngleGearRatio = 150.0 / 7.0;

    
    constexpr units::meter_t WheelCircumference{ 4.0_in * M_PI  };

    const frc::Translation2d m_FrontLeft{14.0_in, -14.0_in};
    const frc::Translation2d m_FrontRight{14.0_in, 14.0_in};
    const frc::Translation2d m_BackLeft{-14.0_in, -14.0_in};
    const frc::Translation2d m_BackRight{-14.0_in, 14.0_in};

    const frc::SwerveDriveKinematics<4> m_kinematics{m_FrontLeft,
                                               m_FrontRight,
                                               m_BackLeft,
                                               m_BackRight};




    /*setting up correct units for the simepleMotorFeedforward KS gain*/
    constexpr units::volt_t DriveKS{0.69719};

    constexpr units::volt_t VoltageKV{2.2575};
    constexpr units::foot_t FeetKV{1.0};
    constexpr units::second_t TimeKV{1.0};
    /*Setting up correct units for the simpleMotorFeedforward KV gain
    Change VoltageKV when wanting to change 
    the KV gain*/
    constexpr auto DriveKV = VoltageKV * TimeKV / FeetKV;

    constexpr units::volt_t VoltageKA{0.35831};
    constexpr units::foot_t FeetKA{1.0};
    constexpr units::second_t TimeKA{1.0};
    /*Setting up correct units for the simpleMotorFeedforward KA gain
    Change VoltageKA when wanting to change the KA gain*/
    constexpr auto DriveKA = VoltageKA * (TimeKA * TimeKA) / FeetKA; 
    constexpr units::volt_t kNominal {12.0};
    /*Angle Encoder Invert*/
    constexpr bool CanCoderInvert = false;

    

    /*Swerve Angle Motor PID gains*/
    constexpr double AngleKP = 0.4;
    constexpr double AngleKI = 0.0;
    constexpr double AngleKD = 0.004;
    constexpr double AngleKF = 0.0;

    /*Swerve Angle Current Limit Config*/
    constexpr bool AngleEnableCurrentLimit = true;
    constexpr int AngleContinuousCurrentLimit = 20;
    constexpr int AnglePeakCurrentLimit = 40;
    constexpr double AnglePeakCurrentDuration = 0.1;


    
    /*Swerve Drive Motor PID gains*/
    constexpr double DriveKP = 0.2;
    constexpr double DriveKI = 0.0;
    constexpr double DriveKD = 0.002;
    constexpr double DriveKF = 0.0;

    /*Swerve Drive Current Limit Config*/
    constexpr bool DriveEnableCurrentLimit = true;
<<<<<<< HEAD
    constexpr int DriveContinuousCurrentLimit = 20;
    constexpr int DrivePeakCurrentLimit = 40;
=======
    constexpr int DriveContinuousCurrentLimit = 30;
    constexpr int DrivePeakCurrentLimit = 50;
>>>>>>> f630e81144ba866e3ed2705e672b98fdcaedf2de
    constexpr double DrivePeakCurrentDuration = 0.1;


    /*Motor Inverts Config*/
    constexpr bool AngleMotorInvert = false;
    constexpr bool DriveMotorInvert = false;


    /* Swerve Profiling values */
    constexpr units::meters_per_second_t MaxSpeed{3};
    constexpr units::degrees_per_second_t MaxAngularVelocity{360};

    constexpr bool IsFieldRelative = true;
    constexpr bool IsOpenLoop = false;  
}


namespace FrontLeftModule{
    constexpr int DriveMotorID = 0;
    constexpr int AngleMotorID = 1;
    constexpr int CanCoderID = 2;
    constexpr double AngleOffset = -54.3;
    const double Constants[4] = { DriveMotorID, AngleMotorID, CanCoderID, AngleOffset };
}

namespace FrontRightModule{
    constexpr int DriveMotorID = 3;
    constexpr int AngleMotorID = 4;
    constexpr int CanCoderID = 5;
    constexpr double AngleOffset = 38.6 ;

    const double Constants[4] = { DriveMotorID, AngleMotorID, CanCoderID, AngleOffset};
}
namespace BackLeftModule{
    constexpr int DriveMotorID = 6;
    constexpr int AngleMotorID = 7;
    constexpr int CanCoderID = 8;
    constexpr auto AngleOffset = 93.6;
    constexpr double Constants[4] = { DriveMotorID, AngleMotorID, CanCoderID, AngleOffset};
}
namespace BackRightModule{
    constexpr int DriveMotorID = 9;
    constexpr int AngleMotorID = 10;
    constexpr int CanCoderID = 11;
    constexpr double AngleOffset = -70.2;
    const double Constants[4] = { DriveMotorID, AngleMotorID, CanCoderID, AngleOffset};
}

namespace AutoConstants{
    constexpr units::radian_t PI {M_PI};
    constexpr units::meters_per_second_t MaxSpeed{ 0 };
    constexpr units::meters_per_second_squared_t MaxAccel{ 0 };
    constexpr units::radians_per_second_t MaxAngularSpeed{ 0 };
    constexpr units::radians_per_second_squared_t MaxAngularAccel{ 0 };


        /*Auto Swerve Drive Motor PID gains*/
    constexpr double AutoDriveKP = 0.0;
    constexpr double AutoDriveKI = 0.0;
    constexpr double AutoDriveKD = 0.0;
    constexpr double AutoDriveKF = 0.0;

        /* Auto Swerve Angle Motor PID gains*/
    constexpr double AutoAngleKP = 0.0;
    constexpr double AutoAngleKI = 0.0;
    constexpr double AutoAngleKD = 0.0;
    constexpr double AutoAngleKF = 0.0;


}

namespace IntakeConstants
{
    constexpr int intakeMotorPort = 16;
    
    constexpr int intakePistonLA = 0;
    constexpr int intakePistonLB = 1;
    constexpr int intakePistonRA = 2;
    constexpr int intakePistonRB = 3;
    

}
namespace IndexerConstants {

    constexpr int indexerID = 15;
    constexpr int breakerPort0 = 0;
    constexpr int breakerPort1 = 1;
    constexpr int breakerPort2 = 2;
    constexpr double percentOutput = 0.2;
    constexpr int xboxRightDPad = 11;

    constexpr int xboxA = 1;
    constexpr int xboxB = 2;
    constexpr int xboxX = 3;
    constexpr int xboxY = 4;
}

namespace ShooterConstants {

  const int hoodID = 19;
  const int flywheel1ID = 20;
  const int flywheel2ID = 21;
  const int turretID = 22;

  const double topOfHood = 0.0;

  const double rotationsCenterToLimit = 0.0;

  const double gravity = -9.806;
  const int kTimeoutMs = 30;
  
<<<<<<< HEAD
  const double kHoodD = 0.08; // Derivative gain
  const double kHoodI = 0.0; // Integral gain
  const double kHoodP = 0.09; // Proportional gain

  const double kFlywheelP = 0.16;
  const double kFlywheelI = 0.0;
  const double kFlywheelD = 0.5;
  const double kFlywheelF = 0.052; 

 

=======
  const double kHoodD = 0.0; // Derivative gain
  const double kHoodI = 0.0; // Integral gain
  const double kHoodP = 0.07; // Proportional gain

  const double kFlywheelP = 0.1;
  const double kFlywheelI = 0.0;
  const double kFlywheelD = 0.0;
  const double kFlywheelF = 0.3; 

  const double kAimP = 0.15;
  const double kAimI = 0.0;
  const double kAimD = 0.0;

>>>>>>> f630e81144ba866e3ed2705e672b98fdcaedf2de
  constexpr static double kRotations = 0.02469136; 
  constexpr static double kHood = 0.03703704;
  constexpr static double kA = 0.02469136; 

  constexpr static double kV = 0.06;

  constexpr double kMaxRpm = 6380;
  const double kRPMTolerance = 200.0;
  const double kFlywheelGearRatio = 16 / 24;
	const double kFlywheelCPR = 2048 /* Falcon CPR */ * kFlywheelGearRatio;

  constexpr static double weeeeeeeeee = 0.0;

   // how many degrees back is your limelight rotated from perfectly vertical?
  constexpr double limelightMountAngleDegrees = 59.0;

  // distance from the center of the Limelight lens to the floor
<<<<<<< HEAD
  constexpr double limelightLensHeightInches = 44.23;
=======
  constexpr double limelightLensHeightInches = 46.6;
>>>>>>> f630e81144ba866e3ed2705e672b98fdcaedf2de

  // distance from the target to the floor
  constexpr double goalHeightInches = 104.0;

  constexpr double desiredLandingAngle = -69.0;
}
