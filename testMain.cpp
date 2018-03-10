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
	multimap<int,char> test;
	
	test = encode.getHistogram();
	
	REQUIRE(test.empty() == true);
	
}

TEST_CASE("Test if create histogram function fills a map")
{	
	ifstream fin;
	Encoder encode;
	fin.open("test.txt");
	
	multimap<int,char> test;
	
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
	
	multimap<int,char> compare;
	multimap<int,char> test;
	
	compare.insert( make_pair(1,-1));
	compare.insert( make_pair(1,10));
	compare.insert( make_pair(1,'1'));
	compare.insert( make_pair(1,'2'));
	compare.insert( make_pair(1,'3'));
	compare.insert( make_pair(1,'4'));
	
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
	
	multimap<int,char> compare;
	multimap<int,char> test;
	
	compare.insert( make_pair(1,-1));
	compare.insert( make_pair(1,10));
	compare.insert( make_pair(1,' '));
	compare.insert( make_pair(1,'1'));
	compare.insert( make_pair(1,'2'));
	compare.insert( make_pair(1,'3'));
	compare.insert( make_pair(1,'4'));

	
	encode.createHistogram(fin);
	test = encode.getHistogram();
	
	
	REQUIRE(compare == test);
}


TEST_CASE("Test if create histogram handles multiple characters")
{	
	ifstream fin;
	Encoder encode;
	fin.open("test3.txt");
	
	if(!fin)
		return;
	
	multimap<int,char> compare;
	multimap<int,char> test;
	
	
	
	
	compare.insert( make_pair(1,-1));
	compare.insert( make_pair(1,10));
	compare.insert( make_pair(1,'5'));
	compare.insert( make_pair(2,'4'));
	compare.insert( make_pair(3,'3'));
	compare.insert( make_pair(4,'2'));
	compare.insert( make_pair(5,'1'));
	compare.insert( make_pair(14,' '));

	encode.createHistogram(fin);
	test = encode.getHistogram();
	
	
	REQUIRE(compare == test);
}

TEST_CASE("Test if create histogram handles multiple characters with new lines")
{	
	ifstream fin;
	Encoder encode;
	fin.open("test4.txt");

	if(!fin)
		return;
	
	multimap<int,char> compare;
	multimap<int,char> test;
	
	compare.insert( make_pair(1,-1));
	compare.insert( make_pair(1,'1'));
	compare.insert( make_pair(1,'2'));
	compare.insert( make_pair(1,'3'));
	compare.insert( make_pair(1,'4'));
	compare.insert( make_pair(4,10));
	
	
	
	encode.createHistogram(fin);
	test = encode.getHistogram();
	
		
	REQUIRE(compare == test);
}

TEST_CASE("Test if create histogram handles multiple characters and capital letters")
{	
	ifstream fin;
	Encoder encode;
	fin.open("test5.txt");

	if(!fin)
		return;
	
	multimap<int,char> compare;
	multimap<int,char> test;
	
	compare.insert( make_pair(1,-1));
	compare.insert( make_pair(1,10));
	compare.insert( make_pair(1,'A'));
	compare.insert( make_pair(1,'a'));
	compare.insert( make_pair(1,'b'));
	
	
	encode.createHistogram(fin);
	test = encode.getHistogram();
	
	REQUIRE(compare == test);
}

TEST_CASE("Test if create histogram handles multiple characters and capital letters 2")
{	
	ifstream fin;
	Encoder encode;
	fin.open("test6.txt");

	if(!fin)
		return;
	
	multimap<int,char> compare;
	multimap<int,char> test;
	
	compare.insert( make_pair(1,-1));
	compare.insert( make_pair(1,10));
	compare.insert( make_pair(4,'A'));
	compare.insert( make_pair(25,'a'));

	encode.createHistogram(fin);
	test = encode.getHistogram();
	
	REQUIRE(compare == test);
}



