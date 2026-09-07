#include "ResourceManager.h"

void Umbrella::ResourceManager::StartUp()
{
	_content = {};
}

void Umbrella::ResourceManager::ShutDown()
{
	_content.clear();
}
