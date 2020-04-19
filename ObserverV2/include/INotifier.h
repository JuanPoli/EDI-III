#define interface struct
#include "IMemoryManagement.h"

interface INotifier: public IMemoryManagement{
    virtual void notify() = 0;
};