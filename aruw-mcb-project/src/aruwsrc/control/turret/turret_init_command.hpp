/*
 * Copyright (c) 2020 Advanced Robotics at the University of Washington <robomstr@uw.edu>
 *
 * This file is part of aruw-mcb.
 *
 * aruw-mcb is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * aruw-mcb is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with aruw-mcb.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __TURRET_INIT_COMMAND_H__
#define __TURRET_INIT_COMMAND_H__

#include <aruwlib/algorithms/contiguous_float.hpp>
#include <aruwlib/control/command.hpp>
#include <modm/math/filter/pid.hpp>

namespace aruwsrc
{
namespace turret
{
class TurretSubsystem;
class TurretInitCommand : public aruwlib::control::Command
{
public:
    explicit TurretInitCommand(TurretSubsystem *subsystem);

    void initialize() override {}
    bool isFinished() const override;

    void execute() override;
    void end(bool) override;

    const char *getName() const override { return "turret init command"; }

private:
    const float YAW_P = 300.0f;
    const float YAW_I = 0.0f;
    const float YAW_D = 100.0f;
    const float YAW_MAX_ERROR_SUM = 0.0f;
    const float YAW_MAX_OUTPUT = 16000;

    const float PITCH_P = 300.0f;
    const float PITCH_I = 0.0f;
    const float PITCH_D = 100.0f;
    const float PITCH_MAX_ERROR_SUM = 0.0f;
    const float PITCH_MAX_OUTPUT = 16000;

    const float pitchTargetAngle = 90.0f;
    const float yawTargetAngle = 90.0f;

    TurretSubsystem *turretSubsystem;

    modm::Pid<float> initYawPid;
    modm::Pid<float> initPitchPid;

    void updateTurretPosition(void);
};

}  // namespace turret

}  // namespace aruwsrc

#endif