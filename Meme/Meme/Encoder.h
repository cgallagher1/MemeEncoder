#pragma once
#include <filesystem>
#include <sys/stat.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std::experimental::filesystem::v1;
using namespace std;

class Encoder
{
public:
	Encoder(string filePath);
	void convertLetters();
	void matrixMult(vector<int> matrixToManipulate);
	~Encoder();

private:
	vector<path> files;
	vector<vector<float>> hiddenMatrix;
	vector <vector<vector<float>>> encodedMatricies;
};

