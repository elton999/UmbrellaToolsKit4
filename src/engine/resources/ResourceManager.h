#pragma once
#include <map>
#include <string>
#include "ResourceContentIntegration.h"

namespace Umbrella
{
	class ResourceManager
	{
		private:
			std::map<std::string, Umbrella::ResourceContentIntegration*> _content;

		public:
			void StartUp();
			void ShutDown();
			bool HasItem(std::string path);

			Umbrella::ResourceContentIntegration* Load(std::string path);
	};
}
