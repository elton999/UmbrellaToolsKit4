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
			int _lenght;

		public:
			void StartUp();
			void ShutDown();
			bool HasContent(std::string path);

			template <typename T>
			T* Load(std::string path)
			{
				T* result;

				// checking if the content is already loaded
				{
					if (HasContent(path))
					{
						try
						{
							result = dynamic_cast<T*>(_content.at(path));
						}
						catch(std::exception e)
						{
							result = nullptr;
						}

						return result;
					}
				}
				
				// load content
				{
					try
					{
						 Umbrella::ResourceContentIntegration* resourceLoad = dynamic_cast<Umbrella::ResourceContentIntegration*>(new T);
						 resourceLoad->Load(path);
						 result = dynamic_cast<T*>(resourceLoad);
						 _content.insert({path, result});
						 _lenght++;
					}
					catch(std::exception e)
					{
						result = nullptr;
					}
				}

				return result;
			}
			void Unload(std::string path);

			int Lenght();
	};
}
