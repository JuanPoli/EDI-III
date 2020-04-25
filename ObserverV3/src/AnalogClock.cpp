#include "../include/IWidget.h"
#include "../include/IClockTimer.h"
#include "../include/SmartPointer.h"
#include <iostream>
#include <sstream>

class AnalogClock:public IObserver, public IWidget {
    
    public:
        AnalogClock (IClockTimer* clockTimer):timer(clockTimer) {
            timer->getSubscriber()->attach(this);
            std::cout << "AnalogClock::AnalogClock" << std::endl;
        }

        virtual ~AnalogClock () {
            std::cout << "AnalogClock::~AnalogClock" << std::endl;
            timer->getSubscriber()->detach(this);
        }

        inline void update () {
            draw();
        }

        inline void draw () {
            std::string hours = std::to_string(timer->getHour());
            std::string minutes = std::to_string(timer->getMinute());
            std::string seconds = std::to_string(timer->getSecond());
            
            if(hours.size() == 1){hours = "0"+hours;}
            if(minutes.size() == 1){minutes = "0"+minutes;}
            if(seconds.size() == 1){seconds = "0"+seconds;}
            std::cout <<"I am Analog: "<< hours<<":"<<minutes<<":"<<seconds<<std::endl;
        }

    private:
    IClockTimer* timer;
};
