#include "huffmanTree.h"

huffmanTree::huffmanTree(unordered_map<char,int>histogram)
{
	unordered_map<char,int>::iterator it;
	//Store all nodes in a minheap descending order
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
		//Construct tree by joining two top nodes
		left = minHeap.top();
		minHeap.pop();
		
		right = minHeap.top();
		minHeap.pop();
		
		//Push newly created node as internal node into min heap
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
	//Pre order traversal generates codes for tree
	if(root == NULL)
		return;	
	
	if(!root->isInternalNode)
	{
		huffmanCodes[root->data] = code;
	}
	
	generateCodes(root->left,code + "0");
	
	generateCodes(root->right,code + "1");
	
	
}

unordered_map<char,string> huffmanTree:: getHuffmanCodes()
{
	return huffmanCodes;
}
