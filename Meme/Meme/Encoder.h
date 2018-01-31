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
	//Public functions that we will use to encode the text
public:
	Encoder(string filePath);
	void convertLetters();
	void matrixMult(vector<int> matrixToManipulate);
	~Encoder();

private:
	//Vector to hold the files
	vector<path> files;
	//Vector to hold our key matrix
	vector<vector<float>> hiddenMatrix;
	//Vector to hold our mulitple encoded matricies
	vector <vector<vector<float>>> encodedMatricies;
};

