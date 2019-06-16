#include <string>
#include "IMessage.h"
#include <ComponentInterface.h>

class NewMessage: public IMessage, public ComponentInterface
{
	public:
		std::string setMessage();
		NewMessage();
		~NewMessage();

		//Component Interface
		bool implements(std::string interfaceName);
        void* getInstance();
        void release();

	private:
		std::string message = "Mensaje de newMessage";
		int referenceCounter;
		bool implemented;
};

	NewMessage::NewMessage():referenceCounter(0){}

	NewMessage::~NewMessage(){}

std::string NewMessage::setMessage()
	{
		return this->message;
	}

	bool NewMessage::implements(std::string interfaceName)
{
    return (interfaceName == "ComponentInterface" || interfaceName == "IMessage") ?
        implemented = true
            : implemented = false;
}

void* NewMessage::getInstance()
{
    if(implemented) {  
    	referenceCounter++;  return this; 
    }
    return NULL;
}

void NewMessage::release()
{
    referenceCounter--;
    if(referenceCounter <= 0) delete this;
}

extern "C" ComponentInterface* create();

ComponentInterface* create()
{
    return (ComponentInterface*) new NewMessage();
}
