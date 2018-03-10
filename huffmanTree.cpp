#include "huffmanTree.h"

huffmanTree::huffmanTree(multimap<int,char>histogram)
{
	multimap<int,char>::iterator it;
	
	for(it = histogram.begin(); it != histogram.end(); it++)
	{
		minHeap.push(new huffmanNode(it->second,it->first));
	}
	
	while(!minHeap.empty())
	{
		cout<<minHeap.top()->frequency<<" "<<minHeap.top()->data<<endl;
		minHeap.pop();
	}
}

void huffmanTree::buildHuffmanTree()
{
	struct huffmanNode *left,*right,*top;
	
	while(minHeap.size() != 1)
	{
		left = minHeap.top();
		minHeap.pop();
		
		right = minHeap.top();
		minHeap.pop();
		
		top = new huffmanNode('*',left->frequency + right->frequency);
		
		top->left = left;
		top->right = right;
		
		minHeap.push(top);
	}

}
