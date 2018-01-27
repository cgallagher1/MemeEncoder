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
//finally it will multiply those 2 X 2 matricies by our hidden matriix
//in order to encode them
void Encoder::convertLetters()
{
	for (int i = 0; i < files.size(); i++)
	{
		//Opens a specific file
		fstream infile;
		infile.open(files[i]);

		//vector to hold all the text from this file
		vector<char> text;

		//Vector that will hold our groups of 4
		vector<vector<char>> groupsOfFour;

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
		for (int i = 0; i < (howManyEvenly * 4); i++)
		{
			vector<char> temp;
			for (int j = 0; j < 4; j++)
			{
				temp.push_back(text[i]);
			}
			groupsOfFour.push_back(temp);
		}
		//Need to fill the remainder with 0's 
		if (difference > 0)
		{
			vector<char> temp;
			for (int i = difference; i > 0; i--)
			{
				temp.push_back(text[text.size() - i]);
			}
			for (int i = temp.size(); i < 4; i++)
			{
				temp.push_back('0');
			}
			groupsOfFour.push_back(temp);
		}
	}
}

Encoder::~Encoder()
{
}