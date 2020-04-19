#ifndef IClockTimer_H
#define IClockTimer_H
#include "ISubscriber.h"

interface IClockTimer: public IMemoryManagement{
        virtual int GetHour() = 0;
        virtual int GetMinute() = 0;
        virtual int GetSecond() = 0;
        virtual ISubscriber* getSubscriber() = 0;
        virtual void Tick() = 0;
};

#endif // IClockTimer_H