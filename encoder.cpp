#include "encoder.h"

Encoder::Encoder(){}

void Encoder::createHistogram(ifstream &fin)
{
	char input;
	map<char,int>::iterator it;

		
	while(fin>>input)
	{
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

map<char,int> Encoder:: getHistogram()
{
	return histogram;
}

