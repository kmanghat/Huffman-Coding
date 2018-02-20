#include "encoder.h"

Encoder::Encoder(){}

void Encoder::createHistogram(ifstream &fin)
{
	char input;
	map<char,int>::iterator it;

	//read till end of file
	while(!fin.eof())
	{
		input = fin.get();
		it = histogram.find(input);
		
		if(it == histogram.end())
		{
			histogram.insert(pair<char,int>(input,1));
		}
		else
		{
			histogram[it->first]++;
		}
		
	}
}

multimap<int,char> Encoder:: getHistogram()
{
	multimap<int,char> orderedHistogram;
	map<char,int>::iterator it;
	
	//returns a map with increasing order of frequency of occuring characters
	for(it = histogram.begin(); it != histogram.end(); it++)
		orderedHistogram.insert(make_pair(it->second,it->first));
		
	return orderedHistogram;
}

