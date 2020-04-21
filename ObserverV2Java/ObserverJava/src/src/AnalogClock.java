package src;

import include.IAnalogClock;
import include.IClockTimer;

public class AnalogClock implements IAnalogClock {

    public AnalogClock(IClockTimer clockTimer) {
        timer = clockTimer;
        timer.getSubscriber().attach(this);
    }

    public void update() {
        draw();
    }


    public void draw() {
        String hours = String.valueOf(timer.getHour());
        String minutes = String.valueOf(timer.getMinute());
        String seconds = String.valueOf(timer.getSecond());

        if (hours.length() == 1) {
            hours = "0" + hours;
        }
        if (minutes.length() == 1) {
            minutes = "0" + minutes;
        }
        if (seconds.length() == 1) {
            seconds = "0" + seconds;
        }
        System.out.println("I am Analog: " + hours + ":" + minutes + ":" + seconds);
    }

    private IClockTimer timer;
}
