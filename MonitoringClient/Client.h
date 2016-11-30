#pragma once
#include "Data.h"
#include "NetClient.cpp"
#include "Account.h"
#include "error.h"

#include <Windows.h>
#include <TlHelp32.h>
#include <LMCons.h>
#include <LM.h>
#include <WtsApi32.h>
#include <UserEnv.h>
#pragma comment(lib, "Userenv.lib")
#pragma comment(lib, "Wtsapi32.lib")

#include <boost/thread.hpp>
#include <boost/chrono.hpp>

#include <boost/regex.hpp>

/*
Read Config
Set member variables
Spawn Administration Thread
Spawn Network Thread
Spawn Gather Data Thread
*/
class Client
{
public:
	Client();
	~Client();
	
	void Run();
	
	void setServer(std::string s);
	std::string getServer();
	void setPort(std::string p);
	std::string getPort();
	void readConfig(std::string file);

private:

	void gather();
	void administration();
	void network();	

	bool loggedIn();

	bool isProgramRunning(std::string p);
	void *buildPacket();

	std::string getCurrentUser();
	void setCurrentUser(std::string s);
	//void setCurrentUser();

	/// Administration functions
	int accountAdministration();

	// Logoff
	void kick();

	/* Member Variables */
	bool RUNNING, LOGGED_IN_;
	NetClient *nc_;

	std::string SERVER_;
	std::string PORT_;

	// Store the currently logged in user name as a string pointer
	std::string CURRENT_USER;

	// Store a map of monitored accounts as regular expression string pointers with their associated account object that contains information about 
	// the account such as allowed / not, time length allowed, etc.
	std::vector<Account> *MONITORED_ACCOUNTS;
	std::map<std::string, time_t> *ACCOUNTS_TRACKED; // contains any users that have logged into the machine but who's time hasn't expired yet
	std::vector<std::string> *EXPIRED_ACCOUNTS; // contains any users whos time has expired

	boost::mutex data_mtx_, li_mtx_;
};