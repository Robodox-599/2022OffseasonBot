// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/cGroup_ClimbTraversal.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
cGroup_ClimbTraversal::cGroup_ClimbTraversal(subsystem_Climb *Climb) {

  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(cGroup_MidRung(Climb),
              frc2::WaitCommand(1.2_s),
              cGroup_HighRung(Climb));

//1.2 seconds is an estimation based on what I saw from 1678 but could need tuning
}
