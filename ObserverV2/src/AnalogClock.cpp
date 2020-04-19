#include "../include/IAnalogClock.h"
#include "../include/IClockTimer.h"
#include <iostream>
#include <sstream>

#define TO_STRING( x ) dynamic_cast< std::ostringstream & >( \
 ( std::ostringstream() << std::dec << x ) ).str()

class AnalogClock: public IAnalogClock {
    
    public:
        AnalogClock (IClockTimer* clockTimer):refCount(0) {
            acquire();
            timer = clockTimer;
            timer->getSubscriber()->Attach(this);
            std::cout << "AnalogClock::AnalogClock" << std::endl;
        }

        virtual ~AnalogClock () {
            std::cout << "AnalogClock::~AnalogClock" << std::endl;
            timer->getSubscriber()->Detach(this);
        }

        void Update () {
            Draw();
        }

        void Draw () {
            std::string hours = TO_STRING(timer->GetHour());
            std::string minutes = TO_STRING(timer->GetMinute());
            std::string seconds = TO_STRING(timer->GetSecond());
            if(hours.size() == 1){hours = "0"+hours;}
            if(minutes.size() == 1){minutes = "0"+minutes;}
            if(seconds.size() == 1){seconds = "0"+seconds;}
            std::cout <<"I am Analog: "<< hours<<":"<<minutes<<":"<<seconds<<std::endl;
        }

        // IMemoryManagement interface implementation

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

