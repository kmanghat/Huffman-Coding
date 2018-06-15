#include "huffmanTree.h"

huffmanTree::huffmanTree(map<char,int>histogram)
{
	map<char,int>::iterator it;
	
	for(it = histogram.begin(); it != histogram.end(); it++)
	{
		if(it->second != 0)
			minHeap.push(new huffmanNode(it->first,it->second,false));
	}
	
}

void huffmanTree::buildHuffmanTree()
{	
	while(minHeap.size() != 1)
	{
		left = minHeap.top();
		minHeap.pop();
		
		right = minHeap.top();
		minHeap.pop();
		
		top = new huffmanNode(' ',left->frequency + right->frequency,true);
		
		top->left = left;
		top->right = right;
		
		minHeap.push(top);
	}
	
}

huffmanNode* huffmanTree::getRoot()
{
	return minHeap.top();
}


void huffmanTree::generateCodes(huffmanNode *root, string code)
{
	if(root == NULL)
		return;	
	
	if(!root->isInternalNode)
	{
		huffmanCodes[root->data] = code;
	}
	
	generateCodes(root->left,code + "0");
	
	generateCodes(root->right,code + "1");
	
	
}

map<char,string> huffmanTree:: getHuffmanCodes()
{
	return huffmanCodes;
}
