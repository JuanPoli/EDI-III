#ifndef ISubscriber_H
#define ISubscriber_H

#include "IObserver.h"
#include <list>

interface ISubscriber {
    virtual void attach(IObserver* observer) = 0;
    virtual void detach(IObserver* observer) = 0;
    virtual std::list<IObserver*> getSubscribers() = 0;
};

#endif // ISubscriber_H