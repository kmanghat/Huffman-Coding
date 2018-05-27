#include "huffmanTree.h"

huffmanTree::huffmanTree(map<char,int>histogram)
{
	map<char,int>::iterator it;
	
	for(it = histogram.begin(); it != histogram.end(); it++)
	{
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


void huffmanTree::printNodes(huffmanNode *root)
{
	if(root == NULL)
		return;	
	
	cout<< root->data<<" "<<root->frequency<<" ";
	
	if(root->isInternalNode == true)
		cout<<"Internal node";
		
	cout<<endl;
	printNodes(root->left);
	
	printNodes(root->right);
	
	
}

