#include "TextResource.h"
#include "../core/platform/FileSystem.h"
#include <assert.h>

void Umbrella::TextResource::Load(std::string path)
{
	_content = Umbrella::FileSystem::Read(path);
}

void Umbrella::TextResource::Unload()
{
	if (!_content.empty())
	{
		_content.clear();
	}
}
