using System;
using System.Collections.Generic;
using System.Text;

namespace Observer.include
{
    public interface IClockTimer {
        int GetHour();
        int GetMinute();
        int GetSecond();
        ISubscriber GetSubscriber();
        void Tick();
    }
}
