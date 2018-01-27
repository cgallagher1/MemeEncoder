#pragma once
#include <filesystem>
#include <sys/stat.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Encoder
{
public:
	Encoder(string filePath);
	void convertLetters();
	~Encoder();

private:
	vector<path> files;
};

