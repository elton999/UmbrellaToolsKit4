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
			bool HasContent(std::string path);

			template <typename T>
			T* Load(std::string path)
			{
				return nullptr;
			}
			void Unload(std::string path);
	};
}
