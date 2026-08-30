#include "Log.h"
#include <iostream>

void Log::Msg(const std::string& msg)
{
	#ifdef BUILD_DEBUG
	std::cerr << "[LOG] " <<  msg << std::endl;
	#endif
}

void Log::MsgError(const std::string& msg)
{
	#ifdef BUILD_DEBUG
	std::cerr << "[ERROR] " <<  msg << std::endl;
	#endif
}

void Log::MsgWarning(const std::string& msg)
{
	#ifdef BUILD_DEBUG
	std::cerr << "[Warning] " <<  msg << std::endl;
	#endif
}
