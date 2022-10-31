// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/cGroup_AutoTaxi.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
cGroup_AutoTaxi::cGroup_AutoTaxi(subsystem_SwerveDrive* SwerveDrive, double Seconds) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(command_Timer(Seconds),
              command_SwerveDriveTeleop(SwerveDrive, [=]{return 0.2;}, [=]{return 0;}, [=]{return 0;}, [=]{return false;}, [=]{return false;}),
              command_Timer(5),
              command_SwerveDriveTeleop(SwerveDrive, [=]{return 0.0;}, [=]{return 0;}, [=]{return 0;}, [=]{return false;}, [=]{return false;})
 );
}
