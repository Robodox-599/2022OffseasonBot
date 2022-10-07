// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "commands/command_Timer.h"
#include "commands/cGroup_MidRung.h"
#include "commands/cGroup_HighRung.h"
#include "commands/cGroup_TraversalRung.h"

#include "subsystems/subsystem_Climb.h"

class cGroup_ClimbTraversal
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 cGroup_ClimbTraversal> {
 public:
  cGroup_ClimbTraversal(subsystem_Climb* Climb, int ticks);
};
