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

class Decoder
{
public:
	Decoder(string filePath, string keyNumbers);
	void getEncodedMatricies();
	void findDET();
	void findInverseMatrix();
	void matrixMult(vector<int>matrixToMulitply);

	~Decoder();

private:
	vector<path> files;
	vector <vector<float>> keyMatrix;
	vector<vector<vector <float>>> encodedMatricies;
	vector<vector<float>> inverseMatrix;
	float DET;
};

