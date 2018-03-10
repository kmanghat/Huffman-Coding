#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include <bits/stdc++.h>


using namespace std;

struct huffmanNode
{
	int frequency;
	char data;
	
	struct huffmanNode *left;
	struct huffmanNode *right;
	
	huffmanNode(char data,int frequency)
	{
		left = NULL;
		right = NULL;
		
		this->data = data;
		this->frequency = frequency;
	}	

};

struct compare
{
	bool operator()(huffmanNode *l, huffmanNode *r)
	{
		return (l->frequency > r->frequency);
	}
};
#endif
