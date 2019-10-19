#include "catch.hpp"
#include "huffmanTree.h"
#include "encoder.h"
#include <bits/stdc++.h>
using namespace std;


TEST_CASE("Test huffmanTree class")
{	
	unordered_map<char,int> test;
	huffmanTree htree(test);
}

TEST_CASE("Test if huffman tree creates a priority queue for a random file")
{	
	ifstream fin;
	Encoder encode;
	fin.open("./test_files/test7.txt");

	if(!fin)
		return;
	
	unordered_map<char,int> test;

	encode.createHistogram(fin);
	test = encode.getHistogram();
	
	map<char,int>::iterator it;
	
	huffmanTree htree(test);
}

TEST_CASE("Test if huffman tree getRoot function returns root of tree")
{	
	ifstream fin;
	Encoder encode;
	huffmanNode *root;
	fin.open("./test_files/test7.txt");

	if(!fin)
		return;
	
	unordered_map<char,int> test;

	encode.createHistogram(fin);
	test = encode.getHistogram();
	
	huffmanTree htree(test);
	
	htree.buildHuffmanTree();
	
	root = htree.getRoot();
	
	REQUIRE((root->data == ' ' && root->frequency == 3738 && root->isInternalNode == true));
	
}

