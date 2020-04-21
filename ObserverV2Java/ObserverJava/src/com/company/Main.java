package com.company;

import include.IAnalogClock;
import include.IClockTimer;
import include.IDigitalClock;
import include.ISubscriber;
import src.AnalogClock;
import src.ClockTimer;
import src.DigitalClock;
import src.Subscriber;

public class Main {

    public static void main(String[] args) {
        ISubscriber subscriber = new Subscriber();
        IClockTimer clockTimer = new ClockTimer(subscriber);
        IAnalogClock analogClock = new AnalogClock(clockTimer);
        IDigitalClock digitalClock = new DigitalClock(clockTimer);

        clockTimer.tick();
        clockTimer.tick();
        clockTimer.tick();
        clockTimer.tick();
        clockTimer.tick();
        clockTimer.tick();
    }
}
