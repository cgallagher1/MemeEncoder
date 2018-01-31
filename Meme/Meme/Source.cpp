#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <math.h>
#include "Encoder.h"
#include "decoder.h"
#include <time.h>

using namespace std;

int main()
{
	//Seeds the random number generator
	srand(time(0));

	//Gets the user input of either encode or decode
	string userAnswer;
	cout << "Would you like to encode or decode a directory (encode / decode)?" << endl;
	cin >> userAnswer;

	//Makes sure that they choose one of the options
	while (userAnswer != "encode" && userAnswer != "decode")
	{
		cout << userAnswer << " was not a valid option, please chose to either encode or decode: " << endl;
		cin >> userAnswer;
	}

	//Encodes
	if (userAnswer == "encode")
	{
		string filePath;
		cout << "Please enter the path to the directory that you would like encoded:" << endl;
		cin >> filePath;

		//Encodes the files
		Encoder toEncode(filePath);
		toEncode.convertLetters();


		//In case there are multiple messages
		string needMore;
		cout << "Do you have another directory to encrypt ot decrypt (y/n): ";
		cin >> needMore;
		while (needMore == "y")
		{
			//Gets the user input
			cout << "Would you like to encode or decode a directory (encode / decode)?" << endl;
			cin >> userAnswer;

			//Makes sure that they choose one of the options
			while (userAnswer != "encode" && userAnswer != "decode")
			{
				cout << userAnswer << " was not a valid option, please chose to either encode or decode: " << endl;
				cin >> userAnswer;
			}
			cout << endl;

			//Encode
			if (userAnswer == "encode")
			{
				//Grabs name of the file that will be passed into the encoder
				cout << "Please enter the path to the directory that you would like encoded:" << endl;
				cin >> filePath;

				//Encodes the files
				Encoder toEncode(filePath);
				toEncode.convertLetters();

				//In case there are multiple messages
				cout << "Do you have another directory to encrypt ot decrypt (y/n): ";
				cin >> needMore;
			}
			//Decode
			else
			{
				//Grabs name of the file that will be passed into the decoder
				cout << "Please enter the path to the directory that you would like decoded:" << endl;
				cin >> filePath;

				Decoder toDecode(filePath);
				toDecode.getEncodedMatricies();

				//In case there are multiple messages
				cout << "Do you have another directory to encrypt ot decrypt (y/n): ";
				cin >> needMore;
			}
		}
	}
	//Decode
	else if (userAnswer == "decode")
	{
		//Gets the files to decode
		string filePath;
		cout << "Please enter the path to the directory that you would like decoded:" << endl;
		cin >> filePath;

		//Decodes the files
		Decoder toDecode(filePath);
		toDecode.getEncodedMatricies();

		//In case there are multiple messages
		string needMore;
		cout << "Do you have another directory to encrypt ot decrypt (y/n): ";
		cin >> needMore;
		while (needMore == "y")
		{
			//Gets the users answer
			cout << "Would you like to encode or decode a directory (encode / decode)?"<< endl;
			cin >> userAnswer;

			//Makes sure they choose one of the availabel options
			while (userAnswer != "encode" && userAnswer != "decode")
			{
				cout << userAnswer << " was not a valid option, please chose to either encode or decode: " << endl;
				cin >> userAnswer;
			}
			cout << endl;

			if (userAnswer == "encode")
			{
				//Grabs name of the file that will be passed into the encoder
				cout << "Please enter the path to the directory that you would like encoded:" << endl;
				cin >> filePath;

				//Encodes the files
				Encoder toEncode(filePath);
				toEncode.convertLetters();

				//In case there are multiple messages
				cout << "Do you have another directory to encrypt ot decrypt (y/n): ";
				cin >> needMore;
			}
			else
			{
				//Grabs name of the file that will be passed into the decoder
				cout << "Please enter the path to the directory that you would like decoded:" << endl;
				cin >> filePath;

				//Decodes the files
				Decoder toDecode(filePath);
				toDecode.getEncodedMatricies();

				//In case there are multiple messages
				cout << "Do you have another directory to encrypt ot decrypt (y/n): ";
				cin >> needMore;
			}
		}
	}

	system("pause");
	return 0;
}