#include <iostream>
#include "../include/IClockTimer.h"
#include "../include/IDigitalClock.h"
#include <sstream>
#define TO_STRING( x ) dynamic_cast< std::ostringstream & >( \
 ( std::ostringstream() << std::dec << x ) ).str()

class DigitalClock: public IDigitalClock
{
    public:
        DigitalClock(IClockTimer* clockTimer):refCount(0){
            acquire();
            timer = clockTimer;
            timer->getSubscriber()->attach(this);
            std::cout << "DigitalClock::DigitalClock" << std::endl;
        }
        virtual ~DigitalClock () {
            std::cout << "DigitalClock::~DigitalClock" << std::endl;
            timer->getSubscriber()->detach(this);
        }

        void update() {
            draw();
        }

        void draw () {
            std::string hours = TO_STRING(timer->getHour());
            std::string minutes = TO_STRING(timer->getMinute());
            std::string seconds = TO_STRING(timer->getSecond());

            if(hours.size() == 1){hours = "0"+hours;}
            if(minutes.size() == 1){minutes = "0"+minutes;}
            if(seconds.size() == 1){seconds = "0"+seconds;}
            std::cout <<"I am Digital: "<< hours<<":"<<minutes<<":"<<seconds<<std::endl;
        }

        // IMemoryManagement implementation

        void acquire(){
            refCount++;
        }

        void release(){
            if(--refCount == 0)
                delete this;
        }

    private:
        int refCount;
        IClockTimer* timer;
};



