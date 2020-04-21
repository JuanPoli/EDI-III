using Observer.include;
using System;
using System.Collections.Generic;
using System.Text;

namespace Observer.src
{
    public class ClockTimer: IClockTimer {

        public ClockTimer(ISubscriber subscriber) {
            notifier = new Notifier(subscriber);
            hours = 0;
            minutes = 0;
            seconds = 0;
            this.subscriber = subscriber;
        }

        public int GetHour()
        {
            return this.hours;
        }

        public int GetMinute()
        {
            return this.minutes;
        }

        public int GetSecond()
        {
            return this.seconds;
        }

        public ISubscriber GetSubscriber()
        {
            return this.subscriber;
        }

        public void Tick()
        {
            seconds++;
            if (seconds == 60)
            {
                seconds = 0;
                minutes++;
                if (minutes == 60)
                {
                    seconds = 0;
                    minutes = 0;
                    hours++;
                    if (hours == 24)
                    {
                        seconds = 0;
                        minutes = 0;
                        hours = 0;
                    }
                }
            }
            notifier.Notify();
        }




        private int hours;
        private int minutes;
        private int seconds;
        private ISubscriber subscriber;
        private INotifier notifier;
    }
}
