#include "src/AnalogClock.cpp"
#include "src/ClockTimer.cpp"
#include "src/DigitalClock.cpp"
#include "src/Subscriber.cpp"
#include "include/SmartPointer.h"

int main()
{
    Smart_ptr<ISubscriber> subscriber  = new Subscriber();
    Smart_ptr<IClockTimer> clockTimer (new ClockTimer(&*subscriber));
    Smart_ptr<AnalogClock> analogClock (new AnalogClock(&*clockTimer));
    Smart_ptr<DigitalClock> digitalClock (new DigitalClock(&*clockTimer));

    
    clockTimer->tick();
    clockTimer->tick();
    clockTimer->tick();
    clockTimer->tick();
    clockTimer->tick();
    clockTimer->tick();
    

 return 0;
}
