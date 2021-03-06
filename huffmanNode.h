#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include <bits/stdc++.h>


using namespace std;

struct huffmanNode
{
	//Frequency of letter 
	int frequency;
	char data;
	//Check if internal node
	bool isInternalNode;
	
	//Left and Right Child
	struct huffmanNode *left;
	struct huffmanNode *right;
	
	huffmanNode(char data,int frequency,bool isInternalNode)
	{
		left = NULL;
		right = NULL;
		
		this->data = data;
		this->frequency = frequency;
		this->isInternalNode = isInternalNode;
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
