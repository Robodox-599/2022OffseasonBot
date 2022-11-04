// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/DriverStation.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc/DigitalInput.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableValue.h>
#include <networktables/NetworkTableInstance.h>
#include "wpi/span.h"

#include <frc2/command/PIDSubsystem.h>
#include <units/angular_velocity.h>
#include <ctre/Phoenix.h>
#include <units/moment_of_inertia.h>
#include <frc/filter/LinearFilter.h>
#include "Constants.h"
#include <frc/smartdashboard/SmartDashboard.h>

class subsystem_Turret : public frc2::SubsystemBase {
 public:
  subsystem_Turret();

  void aimAtTarget();
  void setHoodAngle();

  void startShootAtExitVelocity();
  void endShooter(); 

  //speed mfs
  double getTargetSpeed();
  double getActualSpeed();
  double getShootSpeed();

  double getHoodPosition();

  double getPercentOutput();
  bool isFlyWheelRunning();
  bool isAtTargetRPM();
  double rpmToVelocity(double rpm);
  double rpmToVelocity(units::angular_velocity::revolutions_per_minute_t rpm);
  double velocityToRPM(double velocity);

  bool canSeeTarget();
  // bool setLight(bool on);
  // void toggleLight();

  double findExitVelocity();
  double findExitAngle(); 
  double getTurretRotations();
  

  //calibration 
  // void calibrateLeftEndPoint();
  // void calibrateRightEndPoint();
  void calibrateHoodEndPoint(); 
  void checkTurretCenter();
  // double getLeftEndPoint();
  // double getRightEndPoint();

  double getTurretPosition();
  double getDistanceToGoal();

  //test
  void shootTest(double percent);
  void hoodTest(double pos);


  //special situations
  void shootAlternate(); 
  // void swingTurretAround();
  // bool isAtOppositeEndPoint();

  // nt::NetworkTableEntry mShuffleboardReady;
	// nt::NetworkTableEntry mShuffleboardTargetRPM;
	// nt::NetworkTableEntry mShuffleboardActualRPM;
	// nt::NetworkTableEntry mShuffleboardActualPercent;
	// nt::NetworkTableEntry mShuffleboardBoost;

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:

  // frc::LinearFilter<double> flywheelFilter = frc::LinearFilter<double>::SinglePoleIIR(0.1, 0.02_s);
  bool lightOn = true; 
  float steering_adjust = 0.0f;

  ctre::phoenix::motorcontrol::can::WPI_TalonFX m_FlywheelMotor1;
  ctre::phoenix::motorcontrol::can::WPI_TalonFX m_FlywheelMotor2;

  frc::LinearFilter<double> m_FlywheelFilter = frc::LinearFilter<double>::SinglePoleIIR(0.1, 0.02_s);

  rev::CANSparkMax m_TurretMotor;
  rev::CANSparkMax m_HoodMotor;
  rev::SparkMaxRelativeEncoder m_TurretEncoder;
  rev::SparkMaxRelativeEncoder m_HoodEncoder;

  frc::DigitalInput hoodLimitSensor{0};
  frc::DigitalInput leftHallEffect{2};
  frc::DigitalInput rightHallEffect{3};


  rev::SparkMaxPIDController m_HoodPID;
  rev::SparkMaxPIDController m_TurretPID;

  double hoodTestPosition;
  double shooterTestVelocity;

  double angleToGoalDegrees;
  double angleToGoalRadians;
  // frc2::PIDController aimPID;
  // frc2::PIDController hoodPID; 

  std::shared_ptr<nt::NetworkTable> m_table_ptr = nt::NetworkTableInstance::GetDefault().GetTable("limelight-wocky");

  double m_turn;
  double m_rotation; 

  double m_shooterPercent;
  double m_degrees;

  double centerPosition;

  double rpm;
  double exitAngle;
  double hoodAngle;
  double angleRadians;
  double angleDegrees;

  double leftOffset;
  double rightOffset; 

  bool whichEndPoint;
  bool canEndShoot;

  double m_TargetSpeed; // in RPM
	double m_ActualSpeed; // in RPM, calculated in Periodic()
  double m_BoostPercent = 1.00;

  nt::NetworkTableEntry mShuffleboardReady;
	nt::NetworkTableEntry mShuffleboardTargetRPM;
	nt::NetworkTableEntry mShuffleboardActualRPM;
	nt::NetworkTableEntry mShuffleboardActualPercent;
	nt::NetworkTableEntry mShuffleboardBoost;

  bool m_valid; // Whether the limelight has any valid targets (0 or 1)
  double m_tx;  // Horizontal Offset From Crosshair To Target (LL1: -27 degrees to 27 degrees | LL2: -29.8 to 29.8
                  // degrees)
  double m_ty;  // Vertical Offset From Crosshair To Target (LL1: -20.5 degrees to 20.5 degrees | LL2: -24.85 to 24.85
                  // degrees)
  double m_ta;  // Target Area (0% of image to 100% of image)
  double m_ts;  // Skew or rotation (-90 degrees to 0 degrees)
  double m_tl;  // The pipeline’s latency contribution (ms) Add at least 11ms for image capture latency.
  double m_tshort;  // Sidelength of shortest side of the fitted bounding box (pixels)
  double m_tlong;   // Sidelength of longest side of the fitted bounding box (pixels)
  double m_thor;    // Horizontal sidelength of the rough bounding box (0 - 320 pixels)
  double m_tvert;   // Vertical sidelength of the rough bounding box (0 - 320 pixels)
  double m_getpipe; // True active pipeline index of the camera (0 .. 9)
  double m_camtran; // Results of a 3D position solution, 6 numbers: Translation (x,y,y) Rotation(pitch,yaw,roll)
  double m_tx_last; // Horizontal Offset From Crosshair To Target (LL1: -27 degrees to 27 degrees | LL2: -29.8 to 29.8
                      // degrees)
  double m_ty_last; // Vertical Offset From Crosshair To Target (LL1: -20.5 degrees to 20.5 degrees | LL2: -24.85
                      // to 24.85 degrees)
  double m_ta_last; // Target Area (0% of image to 100% of image)
  double m_ts_last; // Skew or rotation (-90 degrees to 0 degrees)
  double m_tl_last; // The pipeline’s latency contribution (ms) Add at least 11ms for image capture latency.
  double m_tshort_last;  // Sidelength of shortest side of the fitted bounding box (pixels)
  double m_tlong_last;   // Sidelength of longest side of the fitted bounding box (pixels)
  double m_thor_last;    // Horizontal sidelength of the rough bounding box (0 - 320 pixels)
  double m_tvert_last;   // Vertical sidelength of the rough bounding box (0 - 320 pixels)
  double m_getpipe_last; // True active pipeline index of the camera (0 .. 9)
  double m_camtran_last; // Results of a 3D position solution, 6 numbers: Translation (x,y,y) Rotation(pitch,yaw,roll)

  double deltaHeight = ShooterConstants::goalHeightInches - ShooterConstants::limelightLensHeightInches; 


  double xDistanceLimelightToGoal;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  double hoodPosition;


  double leftTurretEndPoint;
  double rightTurretEndPoint;
  double hoodEndPoint = 0;
};
