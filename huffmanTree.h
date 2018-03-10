#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <bits/stdc++.h>
#include "huffmanNode.h"

using namespace std;

class huffmanTree
{

	public:
		huffmanTree(multimap<int,char>histogram);
		void buildHuffmanTree();

	private:
		struct huffmanNode *left, *right,*top;
		priority_queue <huffmanNode*, vector<huffmanNode*>,compare> minHeap;
};


#endif

