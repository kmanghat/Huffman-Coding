#include "catch.hpp"
#include "huffmanTree.h"
#include "encoder.h"
#include "decoder.h"
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
	
		unordered_map<char,int> test;
		
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
		unordered_map<char,string> huffmanCodes = htree.getHuffmanCodes();
		
		//Print codes to encoded file
		ofstream fout;
		fout.open(encodedFile);
		//Reset in file for second pass
		fin.clear();
		fin.seekg(0,ios::beg);
		encode.createEncodedFile(fin,fout,huffmanCodes);
		
		encode.printEncoderInformation(huffmanCodes,fout);
		cout<<"Original File is "<<originalFile<<endl;
		cout<<"Encoded File is "<<encodedFile<<endl;
	}
	
	//If decoder
	if(strcmp(argv[1],decoderFlag) == 0)
	{
		string encodedFile = argv[2];
		string decodedFile = argv[3];
		
		Decoder decode;
		ifstream fin; 
		fin.open(encodedFile);
		
		if(!fin)
		{
			cout<<"Error Opening file make sure it is in working directory"<<endl;
			exit(4);
		}
		
		//Create Histogram
		decode.readHistogram(fin);
		unordered_map<char,int> histogram = decode.getHistogram();
		
		//Build tree
		huffmanTree htree(histogram);
		htree.buildHuffmanTree();
		huffmanNode *root = htree.getRoot();
		
		//Create codes for characters
		htree.generateCodes(root,"");
		
		//Get codes
		unordered_map<char,string> huffmanCodes = htree.getHuffmanCodes();
		
		//Give decoder codes
		decode.setCodes(huffmanCodes);
	
		ofstream fout;
		fout.open(decodedFile);
		
		//Create Decoded file
		decode.generateDecodedFile(fin,fout);
		decode.printDecoderInformation();
		cout<<"Encoded file is "<<encodedFile<<endl;
		cout<<"Decoded file is "<<decodedFile<<endl;
	}

	return 0;
}
