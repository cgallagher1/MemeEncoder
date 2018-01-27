#include <filesystem>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <sstream>
#include "Encoder.h"

using namespace std::experimental::filesystem::v1;
using namespace std;


//Gets all the files in the directory
Encoder::Encoder(string filePath)
{
	for (auto & p: directory_iterator(filePath))
	{
		path temp(p);
		files.push_back(temp);
	}
}

void Encoder::convertLetters()
{
	for (int i = 0; i < files.size(); i++)
	{

	}
}

Encoder::~Encoder()
{
}