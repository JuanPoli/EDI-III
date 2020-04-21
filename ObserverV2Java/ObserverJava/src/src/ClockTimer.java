package src;

import include.IClockTimer;
import include.INotifier;
import include.ISubscriber;

public class ClockTimer implements IClockTimer {

    public ClockTimer(ISubscriber subscriber) {
        notifier = new Notifier(subscriber);
        hours = 0;
        minutes = 0;
        seconds = 0;
        this.subscriber = subscriber;
    }

    public int getHour() {
        return this.hours;
    }

    public int getMinute() {
        return this.minutes;
    }

    public int getSecond() {
        return this.seconds;
    }

    public ISubscriber getSubscriber() {
        return this.subscriber;
    }

    public void tick() {
        seconds++;
        if (seconds == 60) {
            seconds = 0;
            minutes++;
            if (minutes == 60) {
                seconds = 0;
                minutes = 0;
                hours++;
                if (hours == 24) {
                    seconds = 0;
                    minutes = 0;
                    hours = 0;
                }
            }
        }
        notifier._notify();
    }


    private INotifier notifier;
    private int hours;
    private int minutes;
    private int seconds;
    private ISubscriber subscriber;
}
