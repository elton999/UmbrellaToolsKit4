#include "FileSystem.h"
#include <iostream>
#include <fstream>

std::string Umbrella::FileSystem::Read(std::string path)
{
	std::string result;
	std::ifstream File(path);

	while (std::getline(File, result))
	{
		std::cout << result;
	}

	File.close();

	return result;
}

void Umbrella::FileSystem::Write(std::string path, std::string content)
{
	std::ofstream File(path);

	File << content;

	File.close();
}
