#include <iostream>
#include <fstream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() {
	struct node* head = new node;
	head = NULL;
    
    ifstream file;
    file.open("treeFile.txt");
    if (!file) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }
    /*else {
        cout << "File opened!";
    }*/
    int integer;
    //file >> integer;
    //head = append(head, integer);
    while (file >> integer)
    {
        cout << integer << endl;
        //head = append(head, integer);
    }
    file.close();
    //print(head);
}

LinkedList::~LinkedList() {
    cout << "Tree deleted";
}

node* LinkedList::append(struct node* prevNode, int value) {
    node* newNode = new node;
    newNode->keyValue = value;
    newNode->leftBranch = NULL;
    newNode->rightBranch = NULL;

    if (prevNode == NULL) {
        return newNode;
    }
    if (value == prevNode->keyValue) {
        return NULL;
    }
    else if (value < prevNode->keyValue) {
        prevNode->leftBranch = append(prevNode, value);
    }
    else {
        prevNode->rightBranch = append(prevNode, value);
    }
}

void LinkedList::print(node* head) {
    node* current = head;
    node* prevNode = NULL;
    int left = 0;
    int right = 0;
    while (current != NULL) {
        ++left;
        cout << "Left Branch: " << left << " | Value: " << current->keyValue << endl;
        if (current->leftBranch == NULL) {
            cout << "End of left branch reached at depth: " << left << endl;
            current = prevNode->rightBranch;
        }
        prevNode = current;
        current = current->leftBranch;
    }
    current = head;
    while (current != NULL) {
        ++right;
        cout << "Right Branch: " << right << " | Value: " << current->keyValue << endl;
        if (current->rightBranch == NULL) {
            cout << "End of right branch reached at depth: " << right << endl;
            current = prevNode->leftBranch;
        }
        prevNode = current;
        current = current->rightBranch;
    }
}