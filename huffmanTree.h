#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <bits/stdc++.h>
#include "huffmanNode.h"

using namespace std;

class huffmanTree
{

	public:
		huffmanTree(map<char,int>histogram);
		void buildHuffmanTree();
		void printNodes(huffmanNode* root, string code);
		huffmanNode* getRoot();

	private:
		struct huffmanNode *left, *right,*top;
		priority_queue <huffmanNode*, vector<huffmanNode*>,compare> minHeap;
};


#endif

