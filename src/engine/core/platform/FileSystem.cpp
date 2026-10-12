#include "FileSystem.h"
#include <iostream>
#include <fstream>

std::string Umbrella::FileSystem::Read(std::string path)
{
	std::string result;
    std::string resultfinal;
	std::ifstream File(path);
    bool isFirstLine = true;

	while (std::getline(File, result))
	{
        if (isFirstLine)
            resultfinal = result;
        else
            resultfinal += "\n" + result;

        isFirstLine = false;
	}

	File.close();

	return resultfinal;
}

void Umbrella::FileSystem::Write(std::string path, std::string content)
{
	std::ofstream File(path);

	File << content;

	File.close();
}
