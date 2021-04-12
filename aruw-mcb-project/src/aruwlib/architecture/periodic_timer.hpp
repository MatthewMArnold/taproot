/*
 * Copyright (c) 2020-2021 Advanced Robotics at the University of Washington <robomstr@uw.edu>
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

#ifndef __PERIODIC_TIMER_HPP__
#define __PERIODIC_TIMER_HPP__

#include "aruwlib/architecture/timeout.hpp"

namespace aruwlib
{
namespace arch
{
template <typename T>
class PeriodicTimer
{
public:
    PeriodicTimer() : period(0) {}

    explicit PeriodicTimer(uint32_t period) : period(period), timeout(period) {}

    void restart() { timeout.restart(period); }
    void restart(uint32_t period)
    {
        this->period = period;
        restart();
    }

    void stop() { timeout.stop(); }

    bool execute()
    {
        if (timeout.execute())
        {
            uint32_t now = T::TimeFunc();

            do
            {
                timeout.expireTime += period;
            } while (timeout.expireTime <= now);

            timeout.isRunning = true;
            timeout.isExecuted = false;
            return true;
        }
        return false;
    }

    bool isStopped() const { return timeout.isStopped(); }

private:
    uint32_t period;
    T timeout;
};

using PeriodicMilliTimer = PeriodicTimer<MilliTimeout>;
using PeriodicMicroTimer = PeriodicTimer<MicroTimeout>;

}  // namespace arch
}  // namespace aruwlib
#endif
