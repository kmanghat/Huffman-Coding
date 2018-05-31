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
		void generateCodes(huffmanNode* root, string code);
		huffmanNode* getRoot();
		map<char,char> getHuffmanCodes();

	private:
		struct huffmanNode *left, *right,*top;
		priority_queue <huffmanNode*, vector<huffmanNode*>,compare> minHeap;
		map<char,char> huffmanCodes;
		int convertToDecimal(string binary);
};


#endif

