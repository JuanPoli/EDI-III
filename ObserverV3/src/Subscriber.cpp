#include "../include/ISubscriber.h"
#include <iostream>

class Subscriber: public ISubscriber {
    public:
    
        Subscriber(){
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
        
    private:
        std::list<IObserver*> _observers;
};
