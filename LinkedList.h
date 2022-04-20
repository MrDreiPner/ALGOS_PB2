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
	void print();
	node* createNode(int value);
	void checkBalance(node* knoten);
	void checkChild(node* knoten, int& topDepth);

	node* getListHead() { return listHead; };
	
private:
	node* listHead;

};

