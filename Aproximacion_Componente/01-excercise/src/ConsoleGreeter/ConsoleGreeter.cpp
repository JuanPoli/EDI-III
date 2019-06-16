/**
* Copyright (c) 2015 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/

#include <iostream>
#include <string>
#include <GreeterIterface.h>
#include <ComponentInterface.h>
#include "IMessage.h"

class ConsoleGreeter : public GreeterInterface, public ComponentInterface
{
    public:
        ConsoleGreeter();
        virtual ~ConsoleGreeter();
        void greet(IMessage* message); //IMessage* message

        //ComponentInterface:
        bool implements(std::string interfaceName);
        void* getInstance();
        void release();

    private:
        int referenceCounter;
        bool implemented;
};

ConsoleGreeter::ConsoleGreeter() : referenceCounter(0){}

ConsoleGreeter::~ConsoleGreeter(){}

void ConsoleGreeter::greet(IMessage* message)
{
    std::cout << "I am the console greeter and the message is: " << message->setMessage() << std::endl;
}

//ComponentInterface:
bool ConsoleGreeter::implements(std::string interfaceName)
{
    return (interfaceName == "ComponentInterface" || interfaceName == "GreeterInterface") ?
        implemented = true
            : implemented = false;
}

void* ConsoleGreeter::getInstance()
{
    if(implemented) {  referenceCounter++;  return this; }
    return NULL;
}

void ConsoleGreeter::release()
{
    referenceCounter--;
    if(referenceCounter <= 0) delete this;
}

extern "C" ComponentInterface* create();

ComponentInterface* create()
{
    return (ComponentInterface*) new ConsoleGreeter();
}
