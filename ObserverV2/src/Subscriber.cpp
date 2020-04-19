#include "../include/ISubscriber.h"
#include <iostream>
#include <stdio.h>

class Subscriber: public ISubscriber
{
    public:
        Subscriber():refCount(0){
            acquire();
            std::cout << "Subscriber::Subscriber" << std::endl;
        }
        
        virtual ~Subscriber(){
            std::cout << "Subscriber::~Subscriber" << std::endl;
        }
        
        void attach (IObserver* o)
        {
            _observers.push_front(o);
        }
        void detach (IObserver* o)
        {
            _observers.remove(o);
        }

        std::list<IObserver*> getSubscribers(){
            return _observers;
        }
        
        // IMemoryManagement interface implementation

        void acquire(){
            refCount++;
        }

        void release(){
            if(--refCount == 0)
                delete this;
        }

    
    private:
        int refCount;
        std::list<IObserver*> _observers;
};


