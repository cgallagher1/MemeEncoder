#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <math.h>
#include "Encoder.h"

using namespace std;

int main()
{
	string userAnswer;
	cout << "Would you like to encode or decode a directory (encode / decode)?" << endl;
	cin >> userAnswer;
	while (userAnswer != "encode" && userAnswer != "decode")
	{
		cout << userAnswer << " was not a valid option, please chose to either encode or decode: " << endl;
		cin >> userAnswer;
	}

	if (userAnswer == "encode")
	{
		string filePath;
		cout << "Please enter the path to the directory that you would like encoded:" << endl;
		cin >> filePath;

		Encoder toEncode(filePath);
		toEncode.convertLetters();


		//In case there are multiple messages
		string needMore;
		cout << "Do you have another directory to encrypt ot decrypt (y/n): ";
		cin >> needMore;
		while (needMore == "y")
		{
			cout << "Would you like to encrypt or decrypt the directory: ";
			cin >> userAnswer;
			cout << endl;

			if (userAnswer == "encrypt")
			{
				//Grabs name of the file that will be passed into the encoder
				cout << "Please enter the path to the directory that you would like encoded:" << endl;
				cin >> filePath;


				//In case there are multiple messages
				cout << "Do you have another directory to encrypt ot decrypt (y/n): ";
				cin >> needMore;
			}
			else
			{
				cout << "Please enter the path to the directory that you would like decoded:" << endl;
				cin >> filePath;

				//In case there are multiple messages
				cout << "Do you have another directory to encrypt ot decrypt (y/n): ";
				cin >> needMore;
			}
		}
	}
	else if (userAnswer == "decode")
	{
		string filePath;
		cout << "Please enter the path to the directory that you would like decoded:" << endl;
		cin >> filePath;

		//In case there are multiple messages
		string needMore;
		cout << "Do you have another directory to encrypt ot decrypt (y/n): ";
		cin >> needMore;
		while (needMore == "y")
		{
			cout << "Would you like to encrypt or decrypt the directory: ";
			cin >> userAnswer;
			cout << endl;

			if (userAnswer == "encrypt")
			{
				//Grabs name of the file that will be passed into the encoder
				cout << "Please enter the path to the directory that you would like encoded:" << endl;
				cin >> filePath;


				//In case there are multiple messages
				cout << "Do you have another directory to encrypt ot decrypt (y/n): ";
				cin >> needMore;
			}
			else
			{
				cout << "Please enter the path to the directory that you would like decoded:" << endl;
				cin >> filePath;

				//In case there are multiple messages
				cout << "Do you have another directory to encrypt ot decrypt (y/n): ";
				cin >> needMore;
			}
		}
	}

	system("pause");
	return 0;
}