// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "commands/command_SwerveDriveTeleop.h""
#include "commands/command_Timer.h"
#include "subsystems/subsystem_SwerveDrive.h"

class cGroup_AutoTaxi
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 cGroup_AutoTaxi> {
 public:
  cGroup_AutoTaxi(subsystem_SwerveDrive* SwerveDrive, double Seconds);
  
};
