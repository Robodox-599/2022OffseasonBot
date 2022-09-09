// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_SwerveDriveAuto.h"

command_SwerveDriveAuto::command_SwerveDriveAuto(subsystem_SwerveDrive* SwerveDrive, std::string TrajFilePath, bool ToReset):
m_SwerveDrive{SwerveDrive}, m_ToReset{ToReset} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_SwerveDrive});
  fs::path deployDirectory = frc::filesystem::GetDeployDirectory();
  deployDirectory = deployDirectory / "paths" / TrajFilePath;
  m_Trajectory = frc::TrajectoryUtil::FromPathweaverJson(deployDirectory.string());
  
}

// Called when the command is initially scheduled.
void command_SwerveDriveAuto::Initialize() {
  if( m_ToReset ){
    m_SwerveDrive->ResetOdometry(m_Trajectory.InitialPose());
  }
  frc::ProfiledPIDController<units::radians> ThetaController{AutoConstants::AutoDriveKP, 
                                              AutoConstants::AutoDriveKI, 
                                              AutoConstants::AutoDriveKD, 
                                              frc::TrapezoidProfile<units::radians>::Constraints{AutoConstants::MaxAngularSpeed,
                                                                                                 AutoConstants::MaxAngularAccel}};

  ThetaController.EnableContinuousInput(0_rad,  units::radian_t{2* AutoConstants::PI} );

  frc2::SwerveControllerCommand<4> swerveControllerCommand(m_Trajectory,
                                                            [this]{return m_SwerveDrive->GetPose();}, 
                                                            SwerveConstants::m_kinematics,
                                                            frc2::PIDController{0,0,0},
                                                            frc2::PIDController{0,0,0},
                                                            ThetaController,
                                                            [this](auto moduleStates) { m_SwerveDrive->SetModuleStates(moduleStates); },
                                                            {m_SwerveDrive});
  m_SwerveDrive->SwerveDrive(0_mps, 0_mps, 0_rad_per_s, false, false);
                                                            
                                                            
                                                            //.AndThen([]{ return m_SwerveDrive->SwerveDrive(0.0, 0.0, 0.0, false, false)});
                                                            
                                                            
  


}

// Called repeatedly when this Command is scheduled to run
void command_SwerveDriveAuto::Execute() {}

// Called once the command ends or is interrupted.
void command_SwerveDriveAuto::End(bool interrupted) {
  m_SwerveDrive -> SwerveDrive(0_mps, 0_mps, 0_rad_per_s, false, false);
}









// Returns true when the command should end.
bool command_SwerveDriveAuto::IsFinished() {
  return false;
}
