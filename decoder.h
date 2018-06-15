#ifndef DECODER_H
#define DECODER_H
#include <bits/stdc++.h>

using namespace std;

class Decoder
{
public:
	Decoder();
	~Decoder();
	//Read histogram from encoded file
	void readHistogram(ifstream &fin);
	//Getter for histogram
	map<char,int> getHistogram();
	//Setter for huffman codes
	void setCodes(map<char,string> codes);
	//Generate Decoded File
	void generateDecodedFile(ifstream &fin, ofstream &fout);
	//Print Decoder information
	void printDecoderInformation();
	
private:
	//Histogram of characters
	map<char,int> histogram;
	//Huffman Codes
	map<string,char> huffmanCodes;
	//Bytes read and written
	long long int bytesRead = 0;
	long long int bytesWritten = 0;


};

#endif
