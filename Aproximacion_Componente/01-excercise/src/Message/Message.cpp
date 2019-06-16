#include <string>
#include "IMessage.h"
#include <ComponentInterface.h>

class Message: public IMessage, public ComponentInterface
{
	public:
		std::string setMessage();
		Message();
		~Message();

		//Component Interface
		bool implements(std::string interfaceName);
        void* getInstance();
        void release();

	private:
		std::string message = "Hola EDI III";
		int referenceCounter;
		bool implemented;
};

	Message::Message():referenceCounter(0){}

	Message::~Message(){}

std::string Message::setMessage()
	{
		return this->message;
	}

	bool Message::implements(std::string interfaceName)
{
    return (interfaceName == "ComponentInterface" || interfaceName == "IMessage") ?
        implemented = true
            : implemented = false;
}

void* Message::getInstance()
{
    if(implemented) {  
    	referenceCounter++;  return this; 
    }
    return NULL;
}

void Message::release()
{
    referenceCounter--;
    if(referenceCounter <= 0) delete this;
}

extern "C" ComponentInterface* create();

ComponentInterface* create()
{
    return (ComponentInterface*) new Message();
}
