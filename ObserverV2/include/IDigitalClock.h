#ifndef IDigitalClock_H
#define IDigitalClock_H

#include "IObserver.h"
#include "IWidget.h"

interface IDigitalClock: public IWidget, public IObserver{

};

#endif // IDigitalClock_H