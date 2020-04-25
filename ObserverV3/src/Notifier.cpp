#include "../include/INotifier.h"
#include "../include/ISubscriber.h"
#include <iostream>

class Notifier: public INotifier{

    public:
        Notifier(ISubscriber* subs):subscribers(subs){
            std::cout << "Notifier::Notifier" << std::endl;
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
                (*it)->update();
            }
        }

    private:
        ISubscriber* subscribers;
};