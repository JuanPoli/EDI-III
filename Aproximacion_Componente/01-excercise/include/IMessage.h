//Added by Juan Cruz Poli

#ifndef I_MESSAGE_H
#define I_MESSAGE_H

#include <string>

class IMessage
{
public:
	 virtual ~IMessage() {}
	 virtual std::string setMessage() = 0;
};

#endif // I_MESSAGE_H