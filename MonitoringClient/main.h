#include "Client.h"

#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <boost/threadpool.hpp>
#include <boost/thread/thread.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include <boost/foreach.hpp> // ini parser
#include <cstdio> // for remove()
#include <fstream> // write/read to file
#include <sys/types.h>
#include <sys/stat.h>


/**
Boost includes
**/
#include <boost/program_options/detail/config_file.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/cmdline.hpp>
#include <boost/program_options/environment_iterator.hpp>
#include <boost/program_options/option.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/value_semantic.hpp>
#include <boost/program_options/detail/config_file.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#ifdef __linux__
#include <unistd.h>
#include <fcntl.h>
#endif
#ifdef _WIN32
#include <Windows.h>
#include <TlHelp32.h>
#include <algorithm>
#include <LMCons.h>
#include <LM.h>
#include <WtsApi32.h>
#include <UserEnv.h>
#pragma comment(lib, "Userenv.lib")
#pragma comment(lib, "Wtsapi32.lib")
#endif