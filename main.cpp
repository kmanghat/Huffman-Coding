#include "catch.hpp"
#include "huffmanTree.h"
#include "encoder.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
	//Check for correct arguments
	if(argc != 4)
	{
		cout<<"Usage ./huffman -opt inputfile outputfile"<<endl;
		exit(1);
	}
	char encoderFlag[3] = "-e";
	char decoderFlag[3] = "-d";
	
	//Check for valid Arguments
	if(strcmp(argv[1],encoderFlag) != 0 &&
	strcmp(argv[1],decoderFlag) != 0)
	{
		cout<<"Please enter valid option -e or -d"<<endl;
		exit(2);
	}
	
	//If encoder
	if(strcmp(argv[1],encoderFlag) == 0)
	{
		string originalFile = argv[2];
		string encodedFile = argv[3];
		
		ifstream fin;
		Encoder encode;
		huffmanNode *root;
		fin.open(originalFile);
		
		//File not found
		if(!fin)
		{
			cout<<"Error Opening file make sure it is in working directory"<<endl;
			exit(4);
		}
	
		map<char,int> test;
		
		//Create histogram characters to corresponding occurences
		encode.createHistogram(fin);
		test = encode.getHistogram();
		
		//build tree using histogram
		huffmanTree htree(test);
		htree.buildHuffmanTree();
		
		//Get top of tree to generate codes
		root = htree.getRoot();
		htree.generateCodes(root,"");
		
		//get codes
		map<char,string> huffmanCodes = htree.getHuffmanCodes();
		
		//Print codes to encoded file
		ofstream fout;
		fout.open(encodedFile);
		//Reset in file for second pass
		fin.clear();
		fin.seekg(0,ios::beg);
		encode.createEncodedFile(fin,fout,huffmanCodes);
		
		encode.printEncoderInformation(huffmanCodes,fout);
	}
	
	//If decoder
	if(strcmp(argv[1],decoderFlag) == 0)
	{
		//do nothing yet
		;
	}

	return 0;
}
