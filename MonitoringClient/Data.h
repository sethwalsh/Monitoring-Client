#include <cstdint>
#include <string>
#include <vector>

using namespace std;

class Data
{
public:
	Data(int pcount);	
	~Data();
	std::vector<uint8_t> BuildEvent(int flag, std::string pdata, std::string user);
	bool SetUser(std::string u);
	bool SetProgramBit(int pos, bool on);
	void EchoEvent();

private:
	std::vector<uint8_t> *EVENT;
	std::string *USER;
	int MAX_PROGRAM_COUNT = 0;
};