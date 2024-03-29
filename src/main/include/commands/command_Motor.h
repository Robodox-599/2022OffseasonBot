// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/subsystem_Motor.h"
#include"subsystems/subsystem_Breakers.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class command_Motor: 
  public frc2::CommandHelper<frc2::CommandBase, command_Motor> {
    public:
      command_Motor(subsystem_Motor* motor, std::function<double()> PercentOutput);

      void Initialize() override;

      void Execute() override;

      void End(bool interrupted) override;

      bool IsFinished() override;

    private:
      subsystem_Motor* m_motor;
      std::function<double()> m_PercentOutput;
};
