package src;

import include.IClockTimer;
import include.IDigitalClock;

public class DigitalClock implements IDigitalClock {

    public DigitalClock(IClockTimer clockTimer) {
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
        System.out.println("I am Digital: " + hours + ":" + minutes + ":" + seconds);
    }

    private IClockTimer timer;

}
