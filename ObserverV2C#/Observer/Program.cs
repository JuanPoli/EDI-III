using Observer.include;
using Observer.src;
using System;

namespace Observer
{
    class Program
    {
        static void Main(string[] args)
        {
            ISubscriber subscriber = new Subscriber();
            IClockTimer clockTimer = new ClockTimer(subscriber);
            IAnalogClock analogClock = new AnalogClock(clockTimer);
            IDigitalClock digitalClock = new DigitalClock(clockTimer);

            clockTimer.Tick();
            clockTimer.Tick();
            clockTimer.Tick();
            clockTimer.Tick();
            clockTimer.Tick();
            clockTimer.Tick();
        }
    }
}
