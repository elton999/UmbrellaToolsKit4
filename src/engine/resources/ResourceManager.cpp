#include "ResourceManager.h"

void Umbrella::ResourceManager::StartUp()
{
	_content = {};
}

void Umbrella::ResourceManager::ShutDown()
{
	for (auto item : _content)
	{
		Umbrella::ResourceContentIntegration* resource = item.second;
		_content[item.first] = nullptr;
		resource->Unload();
		delete resource;
		_lenght--;
	}

	_content.clear();
	_lenght = 0;
}

bool Umbrella::ResourceManager::HasContent(std::string path)
{
	return _content.count(path) == 1;
}

void Umbrella::ResourceManager::Unload(std::string path)
{
	if (HasContent(path))
	{
		Umbrella::ResourceContentIntegration* resource = _content.at(path);
		_content[path] = nullptr;
		_content.erase(path);
		resource->Unload();
		delete resource;
		_lenght--;
	}
}

int Umbrella::ResourceManager::Lenght()
{
	return _lenght;
}
