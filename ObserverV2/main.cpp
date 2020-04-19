#include "src/AnalogClock.cpp"
#include "src/ClockTimer.cpp"
#include "src/DigitalClock.cpp"
#include "src/Subscriber.cpp"

int main()
{
    ISubscriber* subscriber = new Subscriber();
    IClockTimer* clockTimer = new ClockTimer(subscriber);
    IAnalogClock* analogClock = new AnalogClock(clockTimer);
    IDigitalClock* digitalClock = new DigitalClock(clockTimer);
    
    clockTimer->tick();
    clockTimer->tick();
    clockTimer->tick();
    clockTimer->tick();
    clockTimer->tick();
    clockTimer->tick();
    

    digitalClock->release();
    analogClock->release();
    clockTimer->release();
    subscriber->release();
 return 0;
}