// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/subsystem_Breakers.h"
#include "subsystems/subsystem_Motor.h"
#include "subsystems/subsystem_Pico.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class command_Breakers: 
  public frc2::CommandHelper<frc2::CommandBase, command_Breakers> {
    public:
      command_Breakers(subsystem_Breakers* breakers, subsystem_Motor* motor, subsystem_Pico* pico);

      void Initialize() override;

      void Execute() override;

      void End(bool interrupted) override;

      bool IsFinished() override;

    private:
      subsystem_Breakers* m_breakers;
      subsystem_Motor* m_motor;
      subsystem_Pico* m_pico;
};
