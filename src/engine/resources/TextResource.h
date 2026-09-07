#pragma once
#include "ResourceContentIntegration.h"

namespace Umbrella
{
	class TextResource : public ResourceContentIntegration
	{
		private:
			std::string _content;

		public:
			void Load(std::string path) override;
			void Unload() override;

			std::string* GetContent()
			{
				if (_content.empty())
				{
					return nullptr;
				}
				return &_content;
			}
	};
}
