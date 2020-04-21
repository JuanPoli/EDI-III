using Observer.include;
using System;
using System.Collections.Generic;
using System.Text;

namespace Observer.src
{
    public class AnalogClock: IAnalogClock {
        public AnalogClock(IClockTimer clockTimer)
        {
            timer = clockTimer;
            timer.GetSubscriber().Attach(this);
        }

        public void Update()
        {
            Draw();
        }

        public void Draw()
        {
            string hours = timer.GetHour().ToString();
            string minutes = timer.GetMinute().ToString();
            string seconds = timer.GetSecond().ToString();

            if (hours.Length == 1) { hours = "0" + hours; }
            if (minutes.Length == 1) { minutes = "0" + minutes; }
            if (seconds.Length == 1) { seconds = "0" + seconds; }
            Console.WriteLine("I am Analog: " + hours + ":" + minutes + ":" + seconds);
        }

        private IClockTimer timer;
    }
}
