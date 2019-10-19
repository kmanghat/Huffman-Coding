#ifndef ENCODER_H
#define ENCODER_H
#include <bits/stdc++.h>

using namespace std;

class Encoder
{
	public:
		Encoder();
		~Encoder();
		//Create histogram from original file
		void createHistogram(ifstream &fin);
		//Create Encoded file from histogram
		void createEncodedFile(ifstream &fin, ofstream &fout, unordered_map<char,string> huffmanCodes);
		//getter for histogram
		unordered_map<char,int> getHistogram();
		//Print encoder Stats
		void printEncoderInformation(unordered_map<char,string> huffmanCodes,ofstream &fout);
		
	private:
		//Histogram of characters
		unordered_map<char,int> histogram;
		//Helper function to store bits in character
		unsigned char storeInChar(string binary);
		//Byter Read and Written
		long long int bytesRead;
		long long int bytesWritten;
};

#endif


