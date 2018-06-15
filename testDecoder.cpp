#include "catch.hpp"
#include "huffmanTree.h"
#include "encoder.h"
#include "decoder.h"
#include <bits/stdc++.h>
using namespace std;

TEST_CASE("Test creating an instance of decoder")
{	
	Decoder decode;
}


TEST_CASE("Test reading histogram")
{	
	Decoder decode;
	ifstream fin;
	fin.open("out.txt");
	
	decode.readHistogram(fin);
}

TEST_CASE("Create huffman tree using histogram")
{	
	Decoder decode;
	ifstream fin;
	fin.open("out.txt");
	
	decode.readHistogram(fin);
	map<char,int> histogram = decode.getHistogram();
	
	huffmanTree hTree(histogram);
}

TEST_CASE("Generate huffman codes for decoder")
{	
	Decoder decode;
	ifstream fin;
	fin.open("out.txt");
	
	decode.readHistogram(fin);
	map<char,int> histogram = decode.getHistogram();
	
	huffmanTree htree(histogram);
	
	htree.buildHuffmanTree();
	
	huffmanNode *root = htree.getRoot();
	
	htree.generateCodes(root,"");
	
	map<char,string> huffmanCodes = htree.getHuffmanCodes();
	
	map<char,string> compare;
	
	compare[-1] = "1010";
	compare[10] = "1100";
	compare[' '] = "001";
	compare['e'] = "1001";
	compare['g'] = "111";
	compare['h'] = "1011";
	compare['o'] = "01";
	compare['p'] = "000";
	compare['r'] = "1000";
	compare['s'] = "1101";
	
	REQUIRE(compare == huffmanCodes);
}


TEST_CASE("Get codes from huffman tree")
{
	Decoder decode;
	ifstream fin;
	fin.open("out.txt");
	
	decode.readHistogram(fin);
	map<char,int> histogram = decode.getHistogram();
	
	huffmanTree htree(histogram);
	
	htree.buildHuffmanTree();
	
	huffmanNode *root = htree.getRoot();
	
	htree.generateCodes(root,"");
	
	map<char,string> huffmanCodes = htree.getHuffmanCodes();
	
	decode.setCodes(huffmanCodes);
	
}

TEST_CASE("Generate decoded file")
{
	Decoder decode;
	ifstream fin;
	fin.open("out3.txt");
	
	decode.readHistogram(fin);
	map<char,int> histogram = decode.getHistogram();
	
	huffmanTree htree(histogram);
	htree.buildHuffmanTree();
	huffmanNode *root = htree.getRoot();
	
	htree.generateCodes(root,"");
	
	map<char,string> huffmanCodes = htree.getHuffmanCodes();
	
	decode.setCodes(huffmanCodes);
	
	ofstream fout;
	fout.open("decoded.txt");
	
	decode.generateDecodedFile(fin,fout);	
}
