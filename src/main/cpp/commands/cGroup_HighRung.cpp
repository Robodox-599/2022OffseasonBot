// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/cGroup_HighRung.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
cGroup_HighRung::cGroup_HighRung(subsystem_Climb* Climb) {

  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  /*Comes after cGroup_MidRung, it retracts the LeftClimbArm to climb High rung
  and extends RightClimbArm to get to Traversal rung, due to the design of the climb
  RightClimbArm only needs to extend to reach the Traversal rung*/
  AddCommands(command_LeftClimbByPositionRetract(Climb),
              command_RightClimbByPositionExtend(Climb));
}
