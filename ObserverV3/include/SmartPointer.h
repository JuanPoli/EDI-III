//
//  SmartPointer.h
//  SmartForNotComponentEnviroment
//
//  Created by Juan Cruz Poli on 24/04/2020.
//  Copyright © 2020 Juan Cruz Poli. All rights reserved.
//

#ifndef SmartPointer_h
#define SmartPointer_h
#include <iostream>
#define interface struct

interface IReleaser {
    virtual void release() = 0;
};

template<typename T>
class Releaser: public IReleaser {
public:
    
    Releaser(T* type):ty(type) {
    }
    
    ~Releaser() {
    }
    
    void release(){
        delete ty;
        delete this;
    }
private:
    T* ty;
};



template<typename T>
class Smart_ptr
{
public:
    template <typename Type>
    Smart_ptr(Type* p) : px(p),refCount(0),release(new Releaser<Type>(p))
    {
        refCount++;
    }
    
    virtual ~Smart_ptr(void)
    {
        if (--refCount == 0 )
            release->release();
        
    }
    
    T& operator*()
    {
        return *px;
    }
    
    T* operator->()
    {
        return px;
    }
    
private:
    T* px;
    int refCount;
    IReleaser* release;
    Smart_ptr<T>& operator = (const Smart_ptr<T>& lhs);
};

#endif /* SmartPointer_h */
