#pragma once

#include <string>

namespace Umbrella
{
	class FileSystem
	{
		public:
			static std::string Read(std::string path);
			static void Write(std::string path, std::string content);
	};
};
