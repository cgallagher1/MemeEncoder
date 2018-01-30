#include <filesystem>
#include <sys/stat.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <sstream>
#include <fstream>
#include "decoder.h"

//Gets all the files in the directory
//Creates Key Matrix
//Calulates the DET
//Finds the inverse Matrix
Decoder::Decoder(string filePath, string keyNumbers)
{
	//Collects Files
	for (auto & p : directory_iterator(filePath))
	{
		path temp(p);
		files.push_back(temp);
	}

	//Creates the key matrix from the passed in string
	vector<float> temp;
	for (int i = 0; i < keyNumbers.length(); i++)
	{
		temp.push_back(keyNumbers[i]);

		if (temp.size() == 2)
		{
			keyMatrix.push_back(temp);
		}
		temp.clear();
	}

	//Finds the determinant of this matrix
	findDET();

	//Calulates and creates the inverse Matrix
	findInverseMatrix();

}

//Opens the files and gets the text
//Converts the texts to 2 x 2 matricies
//Then decodes by mulitipling the inverse matrix by the texts 2 x 2
void Decoder::getEncodedMatricies()
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
		}

		//Breaks down the overall text to groups of 4 
		vector<int> temp;
		for (int i = 0; i < text.size(); i++)
		{
			temp.push_back(text[i]);
			if (temp.size() == 4)
			{
				groupsOfFour.push_back(temp);
				temp.clear();
			}
		}
		
		//Mulitply our groups of 4 by the inverseKey
		for (int i = 0; i < groupsOfFour.size(); i++)
		{
			matrixMult(groupsOfFour[i]);
		}

		//Removes the old file
		remove(files[i].filename());

		//adds the new encoded file
		ofstream outfile(files[i]);

		for (int i = 0; i < encodedMatricies.size(); i++)
		{
			for (int j = 0; j < encodedMatricies[i].size(); j++)
			{
				for (int k = 0; k < encodedMatricies[i][j].size(); k++)
				{
					char letter = encodedMatricies[i][j][k];
					outfile << letter << " ";
				}
			}
		}

		encodedMatricies.clear();
	}
}

//Finds the DET of the key matrix
void Decoder::findDET()
{
	DET = 1.00 / ((keyMatrix[0][0] * keyMatrix[1][1]) - (keyMatrix[0][1] * keyMatrix[1][0]));
}

void Decoder::findInverseMatrix()
{
	vector <float> rows;
	float r1c1 = (keyMatrix[0][0]);
	float r1c2 = (keyMatrix[0][1]);
	float r2c1 = (keyMatrix[1][0]);
	float r2c2 = (keyMatrix[1][1]);

	//switches a and d
	float temp = r1c1;
	r1c1 = r2c2;
	r2c2 = temp;

	//Switches sign on b and c
	r1c2 = -(r1c2);
	r2c1 = -(r2c1);

	//First Row of inverse key
	r1c1 = r1c1 * DET;
	rows.push_back(r1c1);
	r1c2 = r1c2 * DET;
	rows.push_back(r1c2);
	inverseMatrix.push_back(rows);
	rows.clear();

	//Second Row of inverse key
	r2c1 = r2c1 * DET;
	rows.push_back(r2c1);
	r2c2 = r2c2 * DET;
	rows.push_back(r2c2);
	inverseMatrix.push_back(rows);
	rows.clear();
}

void Decoder::matrixMult(vector<int> matrixToManipulate)
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

	for (int i = 0; i < inverseMatrix.size(); i++)
	{
		float first = 0.0;
		int second = 0.0;
		first = (convertTo2by2[i][0] * inverseMatrix[0][0]) + (convertTo2by2[i][1] * inverseMatrix[1][0]);
		newMatrixRow.push_back(first);
		second = (convertTo2by2[i][0] * inverseMatrix[0][1]) + (convertTo2by2[i][1] * inverseMatrix[1][1]);
		newMatrixRow.push_back(second);
		newMatrix.push_back(newMatrixRow);
		newMatrixRow.clear();
	}
	encodedMatricies.push_back(newMatrix);
}

Decoder::~Decoder()
{
}