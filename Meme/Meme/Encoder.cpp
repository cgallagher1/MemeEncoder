#include <filesystem>
#include <sys/stat.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <sstream>
#include <fstream>
#include "Encoder.h"

using namespace std::experimental::filesystem::v1;
using namespace std;


//Gets all the files in the directory
//and generates a random 2 X 2 matrix6
Encoder::Encoder(string filePath)
{
	for (auto & p: directory_iterator(filePath))
	{
		path temp(p);
		files.push_back(temp);
	}

	vector <float> temp;
	temp.push_back(rand() % 100);
	temp.push_back(rand() % 100);
	hiddenMatrix.push_back(temp);
	temp.clear();
	temp.push_back(rand() % 100);
	temp.push_back(rand() % 100);
	hiddenMatrix.push_back(temp);
}

//convertLetters will first read in a file
//then it will break down the text inside the file into groups of 4
//it will convert those groups of 4 into 2 X 2 matricies and
//finally it will multiply those 2 X 2 matricies by our hidden matrix
//in order to encode them
void Encoder::convertLetters()
{
	for (int i = 0; i < files.size(); i++)
	{
		//Opens a specific file
		fstream infile;
		infile.open(files[i]);

		//vector to hold all the text from this file
		vector<int> text;

		//Vector that will hold our groups of 4
		vector<vector<int>> groupsOfFour;

		//Reads the file and pushes the text into our vector
		string line;
		while (!infile.eof())
		{
			getline(infile, line);
			for (int i = 0; i < line.length(); i++)
			{
				text.push_back(line[i]);
			}
			//Needs to know new line
			text.push_back('\n');
		}

		//Breaks down the overall text to groups of 4 
		int howManyEvenly = text.size() / 4;
		int difference = text.size() - (howManyEvenly * 4);

		vector<int> temp;
		for (int i = 0; i < (howManyEvenly * 4); i++)
		{
			temp.push_back(text[i]);
			if (temp.size() == 4)
			{
				groupsOfFour.push_back(temp);
				temp.clear();
			}
		}

		//Need to fill the remainder with 0's 
		if (difference > 0)
		{
			vector<int> temp;
			for (int i = difference; i > 0; i--)
			{
				temp.push_back(text[text.size() - i]);
			}
			for (int i = temp.size(); i < 4; i++)
			{
				temp.push_back(0);
			}
			groupsOfFour.push_back(temp);
		}

		for (int i = 0; i < groupsOfFour.size(); i++)
		{
			matrixMult(groupsOfFour[i]);
		}
	}
}

void Encoder::matrixMult(vector<int> matrixToManipulate)
{
	vector<vector<float>> convertTo2by2;

	//Converts the values to floats
	float topLeft = matrixToManipulate[0];
	float topRight = matrixToManipulate[1];
	float bottomLeft = matrixToManipulate[2];
	float bottomRight = matrixToManipulate[3];

	//Makes rows and pushes them back to a 2 by 2 matrix
	vector<float> makeRow;
	makeRow.push_back(topLeft);
	makeRow.push_back(topRight);
	convertTo2by2.push_back(makeRow);
	makeRow.clear();
	makeRow.push_back(bottomLeft);
	makeRow.push_back(bottomRight);
	convertTo2by2.push_back(makeRow);


	vector <float> newMatrixRow;
	vector <vector <float>> newMatrix;
	for (int i = 0; i < hiddenMatrix.size(); i++)
	{
		float first = 0.0;
		int second = 0.0;
		first = (convertTo2by2[i][0] * hiddenMatrix[0][0]) + (convertTo2by2[i][1] * hiddenMatrix[1][0]);
		newMatrixRow.push_back(first);
		second = (convertTo2by2[i][0] * hiddenMatrix[0][1]) + (convertTo2by2[i][1] * hiddenMatrix[1][1]);
		newMatrixRow.push_back(second);
		newMatrixRow.clear();
		newMatrix.push_back(newMatrixRow);
	}
	encodedMatricies.push_back(newMatrix);
}

Encoder::~Encoder()
{
}