#pragma once
#include <iostream>
#include <string.h>
#include <fstream>

struct node {
	int keyValue;
	node* leftBranch;
	node* rightBranch;
};

class LinkedList
{
public:
	LinkedList(char* passedFileName);
	virtual ~LinkedList();
	node* append(struct node* head, int value);
	//void print();
	node* createNode(int value);
	void checkBalance(node* knoten);
	void checkChild(node* knoten, int& topDepth);
	void traverseInOrder(node* current);
	void singleNodeSearch(node* subtree, node* current);
	bool checkNode(node* prime, node* sub);
	void subtreeSearch(node* subtree, node* current);
	void traverse(int keyValue, node* current);
	node* getListHead() { return listHead; };

private:
	node* listHead;

};

