#include "encoder.h"

Encoder::Encoder(){}
Encoder::~Encoder(){}
void Encoder::createHistogram(ifstream &fin)
{
	char input;
	unordered_map<char,int>::iterator it;
	
	for(int i = -1; i < 128; i++)
	{
		histogram[i] = 0;
	}

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

void Encoder::createEncodedFile(ifstream &fin, ofstream &fout, unordered_map<char,string> huffmanCodes)
{
	unordered_map<char,int>::iterator it;
	
	for(int i = -1; i < 128; i++)
	{
		fout<<histogram[i]<<endl;
	}
	
	unsigned char buffer;
	char input;
	string temp = "";
	
	//Pass through input file once again
	//If character is found then look it up in the codes
	//Store code in buffer
	bytesRead = 0;
	bytesWritten = 0;
	while(!fin.eof())
	{
		input = fin.get();
		temp += huffmanCodes[input];
		bytesRead++;
		//If size of string is greater than 8 convert it to 
		//binary and print to file
		if(temp.size() >= 8)
		{
			string binary = temp.substr(0,7);
			temp.erase(0,7);
			buffer = storeInChar(binary);
			fout<<buffer;
			bytesWritten++;
		}
	}
	
	//Left over characters
	if(temp.size() != 0)
	{
		while(temp.size() != 8)
			temp += '0';
		
		string binary = temp.substr(0,7);
		temp.erase(0,7);
		buffer = storeInChar(binary);
		fout<<buffer;
		bytesWritten++;
	}

}  

//Converts string to decimal and returns character representing decimal
unsigned char Encoder::storeInChar(string binary)
{
	reverse(binary.begin(),binary.end());
	unsigned int decimal = 0;
	for(int i = 0; i < 8; i++)
	{
		if(binary[i] == '1')
		{
			decimal += pow(2,i);
		}
	}
	
	unsigned char character = decimal;
	return character;
}

void Encoder::printEncoderInformation(unordered_map<char,string> huffmanCodes,ofstream &fout)
{
	cout<<"Huffman Encoder pass one"<<endl;
	cout<<"-------------------------------------"<<endl;
	
	cout<<"Read "<<bytesRead<<" bytes from input file, "<<histogram.size()<<" code words found"<<endl;
	
	cout<<"\n\n";
	cout<<"Huffman code table"<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"ASCII Code"<<setw(30)<<" Huffman Codes"<<endl;
	unordered_map<char,string>::iterator it;
	
	char seperator = ' ';
	for(it = huffmanCodes.begin(); it != huffmanCodes.end(); it++)
	{
		if(histogram[it->first] != 0)
		{
			if(int(it->first) == -1)
			{
				cout<<"EOF "<<"    ( "<<int(it->first)<<" ) ";
				cout<<right<<setw(20)<<setfill(seperator)<<it->second<<endl;
			}
			else if(int(it->first) == 10)
			{
				cout<<"newline "<<"( "<<int(it->first)<<" ) ";
				cout<<right<<setw(20)<<setfill(seperator)<<it->second<<endl;
			}
			else
			{
				cout<<"   "<<it->first<<"    ( "<<int(it->first)<<" )";
				cout<<right<<setw(20)<<setfill(seperator)<<it->second<<endl;
			}
		}
	
	}
	
	cout<<"\n\n";
	cout<<"Huffman Encoder Pass two"<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"Wrote "<<bytesWritten<<" bytes to output file excluding histogram at the begining(258 bytes)"<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"Compression ratio is "<<(double(bytesWritten)/double(bytesRead))*100;
	cout<<" percent"<<endl;
	cout<<"--------------------------------------"<<endl;

}
//getter for histogram
unordered_map<char,int> Encoder:: getHistogram()
{
	return histogram;
}

