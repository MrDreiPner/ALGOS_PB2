#pragma once
#include <iostream>
#include <fstream>

struct node {
	int keyValue;
	node* leftBranch;
	node* rightBranch;
};

class LinkedList
{
public:
	LinkedList();
	virtual ~LinkedList();
	node* append(struct node* prevNode, int value);
	void print(node* head);

};

