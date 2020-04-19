#include "../include/INotifier.h"
#include "../include/ISubscriber.h"
#include <iostream>

class Notifier: public INotifier{

    public:
        Notifier(ISubscriber* subs):refCount(0){
            acquire();
            std::cout << "Notifier::Notifier" << std::endl;
            subscribers = subs;
        }
        virtual ~Notifier(){
            std::cout << "Notifier::~Notifier" << std::endl;
        }

        void notify ()
        {
            std::list<IObserver*>::iterator it;
            std::list<IObserver*> observers = subscribers->getSubscribers();
            for (it = observers.begin() ; it != observers.end(); ++it)
            {
                (*it)->Update();
            }
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
        ISubscriber* subscribers;
};