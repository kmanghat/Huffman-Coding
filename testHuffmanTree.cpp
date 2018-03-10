#include "catch.hpp"
#include "huffmanTree.h"
#include "encoder.h"
#include <bits/stdc++.h>
using namespace std;


TEST_CASE("Test huffmanTree class")
{	
	multimap<int,char> test;
	huffmanTree htree(test);
}

TEST_CASE("Test if huffman tree creates a priority queue for a random file")
{	
	ifstream fin;
	Encoder encode;
	fin.open("test7.txt");

	if(!fin)
		return;
	
	multimap<int,char> test;

	encode.createHistogram(fin);
	test = encode.getHistogram();
	
	huffmanTree htree(test);
}
