#ifndef IClockTimer_H
#define IClockTimer_H
#include "ISubscriber.h"

interface IClockTimer {
        virtual int getHour() = 0;
        virtual int getMinute() = 0;
        virtual int getSecond() = 0;
        virtual ISubscriber* getSubscriber() = 0;
        virtual void tick() = 0;
};

#endif // IClockTimer_H