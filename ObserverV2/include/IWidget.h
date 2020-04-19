#ifndef IWidget_H
#define IWidget_H
#include "IMemoryManagement.h"

interface IWidget: public IMemoryManagement {
        virtual void draw() = 0;
};

#endif // IWidget_H