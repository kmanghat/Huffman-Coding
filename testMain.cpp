#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "encoder.h"
#include <fstream>
#include <unordered_map>
using namespace std;


TEST_CASE("Test for encoder interface")
{	
	Encoder encode;
}

TEST_CASE("Test for getHistogram function")
{	
	Encoder encode;
	unordered_map<char,int> test;
	
	test = encode.getHistogram();
	
	REQUIRE(test.empty() == true);
	
}

TEST_CASE("Test if create histogram function fills a map")
{	
	ifstream fin;
	Encoder encode;
	fin.open("./test_files/test.txt");
	
	unordered_map<char,int> test;
	
	encode.createHistogram(fin);
	test = encode.getHistogram();
	
	
	REQUIRE(test.empty() == false);
}

TEST_CASE("Test if create histogram function fills correct values for a letter occuring once")
{	
	ifstream fin;
	Encoder encode;
	fin.open("./test_files/test.txt");
	
	if(!fin)
		return;
	
	unordered_map<char,int> compare;
	unordered_map<char,int> test;
	
	for(int i = -1; i < 128; i++)
		compare[i] = 0;
	
	compare[-1] = 1;
	compare[10] = 1;
	compare['1'] = 1;
	compare['2'] = 1;
	compare['3'] = 1;
	compare['4'] = 1;
	
	encode.createHistogram(fin);
	test = encode.getHistogram();
	
	REQUIRE(compare == test);
}

TEST_CASE("Test if create histogram handles spaces")
{	
	ifstream fin;
	Encoder encode;
	fin.open("./test_files/test1.txt");
	
	if(!fin)
		return;
	
	unordered_map<char,int>compare;
	unordered_map<char,int> test;
	
	for(int i = -1; i < 128; i++)
		compare[i] = 0;
	
	compare[-1] = 1;
	compare[10] = 1;
	compare['1'] = 1;
	compare['2'] = 1;
	compare['3'] = 1;
	compare['4'] = 1;
	compare[' '] = 1;
	
	encode.createHistogram(fin);
	test = encode.getHistogram();
	
	
	REQUIRE(compare == test);
}


TEST_CASE("Test if create histogram handles multiple characters")
{	
	ifstream fin;
	Encoder encode;
	fin.open("./test_files/test3.txt");
	
	if(!fin)
		return;
	
	unordered_map<char,int>compare;
	unordered_map<char,int> test;
	
	for(int i = -1; i < 128; i++)
		compare[i] = 0;
	
	compare[-1] = 1;
	compare[10] = 1;
	compare['1'] = 5;
	compare['2'] = 4;
	compare['3'] = 3;
	compare['4'] = 2;
	compare['5'] = 1;
	compare[' '] = 14;
	

	encode.createHistogram(fin);
	test = encode.getHistogram();
	
	
	REQUIRE(compare == test);
}

TEST_CASE("Test if create histogram handles multiple characters with new lines")
{	
	ifstream fin;
	Encoder encode;
	fin.open("./test_files/test4.txt");

	if(!fin)
		return;
	
	unordered_map<char,int>compare;
	unordered_map<char,int> test;
	
	for(int i = -1; i < 128; i++)
		compare[i] = 0;
		
	compare[-1] = 1;
	compare[10] = 4;
	compare['1'] = 1;
	compare['2'] = 1;
	compare['3'] = 1;
	compare['4'] = 1;
	
	encode.createHistogram(fin);
	test = encode.getHistogram();
	
		
	REQUIRE(compare == test);
}

TEST_CASE("Test if create histogram handles multiple characters and capital letters")
{	
	ifstream fin;
	Encoder encode;
	fin.open("./test_files/test5.txt");

	if(!fin)
		return;
	
	unordered_map<char,int>compare;
	unordered_map<char,int> test;
	
	for(int i = -1; i < 128; i++)
		compare[i] = 0;

	compare.insert( make_pair(-1,1));
	compare.insert( make_pair(10,1));
	compare.insert( make_pair('A',1));
	compare.insert( make_pair('a',1));
	compare.insert( make_pair('b',1));
	
	compare[-1] = 1;
	compare[10] = 1;
	compare['A'] = 1;
	compare['a'] = 1;
	compare['b'] = 1;
	
	encode.createHistogram(fin);
	test = encode.getHistogram();
	
	REQUIRE(compare == test);
}

TEST_CASE("Test if create histogram handles multiple characters and capital letters 2")
{	
	ifstream fin;
	Encoder encode;
	fin.open("./test_files/test6.txt");

	if(!fin)
		return;
	
	unordered_map<char,int>compare;
	unordered_map<char,int> test;
	
	for(int i = -1; i < 128; i++)
		compare[i] = 0;
	
	compare[-1] = 1;
	compare[10] = 1;
	compare['A'] = 4;
	compare['a'] = 25;
	
	encode.createHistogram(fin);
	test = encode.getHistogram();
	
	REQUIRE(compare == test);
}



