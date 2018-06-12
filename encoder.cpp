#include "encoder.h"

Encoder::Encoder(){}

void Encoder::createHistogram(ifstream &fin)
{
	char input;
	map<char,int>::iterator it;

	//read till end of file
	while(!fin.eof())
	{
		input = fin.get();
		it = histogram.find(input);
		
		//get character and if found in histogram increment else add
		if(it == histogram.end())
		{
			histogram.insert(pair<char,int>(input,1));
		}
		else
		{
			histogram[it->first]++;
		}
		
	}
}

void Encoder::createEncodedFile(ifstream &fin, ofstream &fout, map<char,string> huffmanCodes)
{
	map<char,int>::iterator it;
	
	for(it = histogram.begin(); it != histogram.end(); it++)
	{
		fout<<it->first<<" "<<it->second<<endl;
	}
	
	unsigned char buffer;
	char input;
	string temp = "";
	
	//Pass through input file once again
	//If character is found then look it up in the codes
	//Store code in buffer
	while(!fin.eof())
	{
		input = fin.get();
		temp += huffmanCodes[input];
		
		//If size of string is greater than 8 convert it to 
		//binary and print to file
		if(temp.size() >= 8)
		{
			string binary = temp.substr(0,7);
			temp.erase(0,7);
			buffer = storeInChar(binary);
			fout<<buffer;
		}
	}
	
}  

//Converts string to decimal and returns character representing decimal
unsigned char Encoder::storeInChar(string binary)
{
	int decimal = 0;
	for(int i = 0; i < 8; i++)
	{
		if(binary[i] == '1')
		{
			decimal += pow(2,i);
		}
	}
	
	return char(decimal);
}

//getter for histogram
map<char,int> Encoder:: getHistogram()
{
	return histogram;
}

