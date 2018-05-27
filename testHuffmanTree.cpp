#include "catch.hpp"
#include "huffmanTree.h"
#include "encoder.h"
#include <bits/stdc++.h>
using namespace std;


TEST_CASE("Test huffmanTree class")
{	
	map<char,int> test;
	huffmanTree htree(test);
}

TEST_CASE("Test if huffman tree creates a priority queue for a random file")
{	
	ifstream fin;
	Encoder encode;
	fin.open("test7.txt");

	if(!fin)
		return;
	
	map<char,int> test;

	encode.createHistogram(fin);
	test = encode.getHistogram();
	
	map<char,int>::iterator it;
	
	/*
	for(it = test.begin(); it!= test.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	*/
	huffmanTree htree(test);
}

TEST_CASE("Test if huffman tree getRoot function returns root of tree")
{	
	ifstream fin;
	Encoder encode;
	huffmanNode *root;
	fin.open("test7.txt");

	if(!fin)
		return;
	
	map<char,int> test;

	encode.createHistogram(fin);
	test = encode.getHistogram();
	
	huffmanTree htree(test);
	
	htree.buildHuffmanTree();
	
	root = htree.getRoot();
	
	REQUIRE((root->data == ' ' && root->frequency == 3738 && root->isInternalNode == true));
	
}


TEST_CASE("Test if huffman tree prints correct values(for debugging)")
{	
	ifstream fin;
	Encoder encode;
	huffmanNode *root;
	fin.open("8mb.txt");

	if(!fin)
		return;
	
	map<char,int> test;

	encode.createHistogram(fin);
	test = encode.getHistogram();
	
	huffmanTree htree(test);
	
	htree.buildHuffmanTree();
	
	root = htree.getRoot();
	
	htree.printNodes(root);
		
}

