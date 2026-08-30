#pragma once

#include <string>

class Log
{
	public:
		static void Msg(const std::string& msg);
		static void MsgError(const std::string& msg);
		static void MsgWarning(const std::string& msg);
};
