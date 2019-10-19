#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <bits/stdc++.h>
#include "huffmanNode.h"

using namespace std;

class huffmanTree
{

	public:
		huffmanTree(unordered_map<char,int>histogram);
		void buildHuffmanTree();
		void generateCodes(huffmanNode* root, string code);
		huffmanNode* getRoot();
		unordered_map<char,string> getHuffmanCodes();

	private:
		struct huffmanNode *left, *right,*top;
		priority_queue <huffmanNode*, vector<huffmanNode*>,compare> minHeap;
		unordered_map<char,string> huffmanCodes;
};


#endif

