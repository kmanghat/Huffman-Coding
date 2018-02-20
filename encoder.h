#ifndef ENCODER_H
#define ENCODER_H
#include <bits/stdc++.h>

using namespace std;

class Encoder
{
	public:
		Encoder();
		void createHistogram(ifstream &fin);
		multimap<int,char> getHistogram();
		
		
	private:
		map<char,int> histogram;
};

#endif


