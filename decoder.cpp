#include "decoder.h"

Decoder::Decoder(){};
Decoder::~Decoder(){};
//Read Histogram From Encoded File
void Decoder::readHistogram(ifstream &fin)
{
	int input;
	for(int i = -1; i < 128; i++)
	{
		fin>>input;
		histogram[i] = input;
	}

}

//getter for histogram
unordered_map<char,int> Decoder::getHistogram()
{
	return histogram;
}

//Setter for huffman codes
void Decoder::setCodes(unordered_map<char,string> codes)
{
	unordered_map<char,string>::iterator it;
	
	for(it = codes.begin(); it != codes.end(); it++)
	{
		huffmanCodes[it->second] = it->first;
	}

}

//Generate Decoded file from encoded file
void Decoder::generateDecodedFile(ifstream &fin,ofstream &fout)
{
	unsigned char input;
	string temp = "";
	string binary = "";
	bool end = false;
	//first character is not needed since text files contain character 10 in the begining
	fin>>noskipws>>input;
	bytesRead++;
	//no skips because space maybe a character
	while(fin>>noskipws>>input && end == false)
	{
		bytesRead++;
		//look for set bits in the char and convert to binary
		for(int i = 0;i < 8; i++)
		{
			if(((1<<i) & input) != 0)
			{
				temp += '1';
			}
			else
			{
				temp += '0';
			}
		}
		//Reverse and add onto binary code
		reverse(temp.begin(),temp.end());
		temp.erase(0,1);
		binary += temp;
		
		//loop through entire code looking for particular code
		//If found print that character to screen and erase that section of code
		for(unsigned int i = 0; i < binary.size(); i++)
		{
			string checkForCode = binary.substr(0,i);
			if(huffmanCodes.count(checkForCode) != 0)
			{	
				if(huffmanCodes[checkForCode] == -1)
				{
					end = true;
				}
				else
				{
					binary.erase(0,i);
					i = 0;
					char output = huffmanCodes[checkForCode];
					fout<<output;
					bytesWritten++;
				}
			}
			
		}
		
		temp.clear();
	}
}


void Decoder:: printDecoderInformation()
{
	cout<<"Huffman Decoder"<<endl;
	cout<<"-----------------------------------"<<endl;
	cout<<"Bytes Read "<<bytesRead<<endl;
	cout<<"Bytes Written "<<bytesWritten<<endl;
	cout<<"Compression Ratio is "<<double(bytesRead)/double(bytesWritten)*100<<" percent"<<endl;
	cout<<"-----------------------------------"<<endl;
}
