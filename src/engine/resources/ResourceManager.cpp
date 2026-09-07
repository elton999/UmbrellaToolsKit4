#include "ResourceManager.h"

void Umbrella::ResourceManager::StartUp()
{
	_content = {};
}

void Umbrella::ResourceManager::ShutDown()
{
	_content.clear();
}

bool Umbrella::ResourceManager::HasContent(std::string path)
{
	return false;
}

void Umbrella::ResourceManager::Unload(std::string path)
{

}
