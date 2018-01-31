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
	//Public functions that we will use to decode the text
public:
	Decoder(string filePath);
	void getEncodedMatricies();
	void findDET();
	void findInverseMatrix();
	void matrixMult(vector<int>matrixToMulitply);

	~Decoder();

private:
	//Holds the files
	vector<path> files;
	//Holds our key matrix
	vector <vector<float>> keyMatrix;
	//Holds our read in encoded matricies
	vector<vector<vector <float>>> encodedMatricies;
	//Holds our calculated inverse matrix
	vector<vector<float>> inverseMatrix;
	//Holds our calcualted determinant of our
	//key matrix
	float DET;
};

