#pragma once

#include <string>

namespace Umbrella
{
	class ResourceContentIntegration
	{
		public:
			virtual void Load(std::string path);
			virtual void Unload();
	};
}
