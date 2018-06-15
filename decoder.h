#ifndef DECODER_H
#define DECODER_H
#include <bits/stdc++.h>

using namespace std;

class Decoder
{
public:
	void readHistogram(ifstream &fin);
	map<char,int> getHistogram();
	void setCodes(map<char,string> codes);
	void generateDecodedFile(ifstream &fin, ofstream &fout);
	void printDecoderInformation();
	
private:
	map<char,int> histogram;
	map<string,char> huffmanCodes;
	long long int bytesRead = 0;
	long long int bytesWritten = 0;


};

#endif
