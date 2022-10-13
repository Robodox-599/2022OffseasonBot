// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelCommandGroup.h>
#include "commands/command_LeftClimbByPositionRetract.h"
#include "commands/command_RightClimbByPositionExtend.h"
#include "subsystems/subsystem_Climb.h"

class cGroup_HighRung
    : public frc2::CommandHelper<frc2::ParallelCommandGroup,
                                 cGroup_HighRung> {
 public:
  cGroup_HighRung(subsystem_Climb* Climb);
};
