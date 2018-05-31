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


void huffmanTree::generateCodes(huffmanNode *root, string code)
{
	if(root == NULL)
		return;	
	
	if(!root->isInternalNode)
	{
		int codeInDecimal = convertToDecimal(code);
		huffmanCodes[root->data] = char(codeInDecimal);
		cout<< root->data<<" "<<root->frequency<<" "<<code<<" "<<"\n";
	}
	
	generateCodes(root->left,code + "0");
	
	generateCodes(root->right,code + "1");
	
	
}

int huffmanTree::convertToDecimal(string binary)
{
	reverse(binary.begin(),binary.end());
	int decimal = 0;
	int size = binary.size();
	for(int i = 0; i < size; i++)
	{
		if(binary[i] == '1')
		{
			decimal += pow(2,i);
		}
			
	}
	
	return decimal;
	
}
map<char,char> huffmanTree:: getHuffmanCodes()
{
	return huffmanCodes;
}
