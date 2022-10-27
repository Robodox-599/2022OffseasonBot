// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/cGroup_MidRung.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
cGroup_MidRung::cGroup_MidRung(subsystem_Climb* Climb) {

  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  /*Happens after RightClimbArm is raised, 
  This command retracts RightClimbArm to climb Mid Rung 
  and extends LeftClimbArm to prepare for High Rung*/ 
  AddCommands(command_RightClimbByPositionRetract(Climb),
              command_LeftClimbByPositionExtend(Climb)
              );
}