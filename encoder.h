#ifndef ENCODER_H
#define ENCODER_H
#include <bits/stdc++.h>

using namespace std;

class Encoder
{
	public:
		Encoder();
		void createHistogram(ifstream &fin);
		void createEncodedFile(ifstream &fin, ofstream &fout, map<char,string> huffmanCodes);
		map<char,int> getHistogram();
		void printEncoderInformation(map<char,string> huffmanCodes,ofstream &fout);
		
	private:
		map<char,int> histogram;
		unsigned char storeInChar(string binary);
		long long int bytesRead;
		long long int bytesWritten;
};

#endif


