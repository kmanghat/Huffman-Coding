#include "catch.hpp"
#include "huffmanTree.h"
#include "encoder.h"
#include <bits/stdc++.h>
using namespace std;

TEST_CASE("Test if encoder prints to text file")
{	
	ifstream fin;
	Encoder encode;
	huffmanNode *root;
	fin.open("./test_files/test8.txt");

	if(!fin)
		return;
	
	unordered_map<char,int> test;
	
	encode.createHistogram(fin);
	test = encode.getHistogram();
	
	huffmanTree htree(test);
	
	htree.buildHuffmanTree();
	
	root = htree.getRoot();
	
	htree.generateCodes(root,"");
	
	unordered_map<char,string> huffmanCodes = htree.getHuffmanCodes();
	
	ofstream fout;
	fout.open("out.txt");
	fin.clear();
	fin.seekg(0,ios::beg);
	encode.createEncodedFile(fin,fout,huffmanCodes);
	
		
}

