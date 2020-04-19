#ifndef IMemoryManagement_H
#define IMemoryManagement_H

#define interface struct

interface IMemoryManagement {
    virtual void acquire() = 0;
    virtual void release() = 0;
};

#endif // IMemoryManagement_H