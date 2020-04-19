#ifndef ISubscriber_H
#define ISubscriber_H

#include "IMemoryManagement.h"
#include "IObserver.h"
#include <list>

interface ISubscriber: public IMemoryManagement{
    virtual void attach(IObserver* observer) = 0;
    virtual void detach(IObserver* observer) = 0;
    virtual std::list<IObserver*> getSubscribers() = 0;
};

#endif // ISubscriber_H