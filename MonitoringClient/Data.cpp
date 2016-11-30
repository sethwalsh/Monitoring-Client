#include "Data.h"

Data::Data(int pcount)
{
	MAX_PROGRAM_COUNT = pcount;

	// Set the initial EVENT to 0
	this->EVENT = new std::vector<uint8_t>();
}

Data::~Data()
{
	delete EVENT;
}

std::vector<unsigned char> Data::BuildEvent(int flag, std::string pdata, std::string user)
{
	std::vector<unsigned char> _result;
	uint16_t _flag = flag;
	this->EVENT->push_back(_flag);

	return _result;
}

bool Data::SetUser(std::string u)
{
	return false;
}

bool Data::SetProgramBit(int pos, bool on)
{
	return false;
}

void Data::EchoEvent()
{
	
}