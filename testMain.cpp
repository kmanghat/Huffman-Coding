#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "encoder.h"
#include <fstream>
using namespace std;


TEST_CASE("Test for encoder interface")
{	
	Encoder encode;
}

TEST_CASE("Test for getHistogram function")
{	
	Encoder encode;
	map<char,int> test;
	
	test = encode.getHistogram();
	
	REQUIRE(test.empty() == true);
	
}

TEST_CASE("Test if create histogram function fills a map")
{	
	ifstream fin;
	Encoder encode;
	fin.open("test.txt");
	
	map<char,int> test;
	
	encode.createHistogram(fin);
	test = encode.getHistogram();
	
	
	REQUIRE(test.empty() == false);
}

TEST_CASE("Test if create histogram function fills correct values for a letter occuring once")
{	
	ifstream fin;
	Encoder encode;
	fin.open("test.txt");
	
	if(!fin)
		return;
	
	map<char,int> compare;
	map<char,int> test;
	
	
	compare['1']=1;
	compare['2']=1;
	compare['3']=1;
	compare['4']=1;
	compare[10] = 1;
	
	
	encode.createHistogram(fin);
	test = encode.getHistogram();
	
	
	REQUIRE(compare == test);
}

TEST_CASE("Test if create histogram handles spaces")
{	
	ifstream fin;
	Encoder encode;
	fin.open("test1.txt");
	
	if(!fin)
		return;
	
	map<char,int> compare;
	map<char,int> test;
	
	compare[' ']=1;
	compare['1']=1;
	compare['2']=1;
	compare['3']=1;
	compare['4']=1;
	compare[10] = 1;

	
	encode.createHistogram(fin);
	test = encode.getHistogram();
	
	
	REQUIRE(compare == test);
}
