#ifndef IWidget_H
#define IWidget_H
#include "IMemoryManagement.h"

interface IWidget: public IMemoryManagement {
        virtual void Draw() = 0;
};

#endif // IWidget_H