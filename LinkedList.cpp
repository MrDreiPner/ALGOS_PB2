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
    file >> integer;
    //cout << integer << endl;
    head = append(head, integer);
    while (file >> integer)
    {
        //cout << integer << endl;
        append(head, integer);
    }
    file.close();
    //print(head);
}

LinkedList::~LinkedList() {
    cout << "Tree deleted";
}

node* LinkedList::append(struct node* head, int value) {
    node* current = head;
    node* prev = NULL;
    int left = 0;
    int right = 0;
    int depth = 0;
    if (head == NULL) {
        cout << "Root depth: 0 | Value: " << value << endl;
        node* newNode = createNode(value);
        return newNode;
    }
    while (current != NULL) {
        ++depth;
        if (value == current->keyValue) {
            cout << " FAIL! Duplicate found -> Value: " << value << " has been dropped!" << endl;
            break;
        }
        else if (value < current->keyValue) {
            prev = current;
            current = current->leftBranch;
            cout << "L->";
            ++left;
            if (current == NULL) {
                cout << " Done! --> Right depth: " << right << " | Left Depth: " << left << " | Overall Depth: " << depth << " | Value: " << value << endl;
                node* newNode = createNode(value);
                prev->leftBranch = newNode;
                return head;
            }
        }
        else {
            prev = current;
            current = current->rightBranch;
            cout << "R->";
            ++right;
            if (current == NULL) {
                cout << " Done! --> Right depth: " << right << " | Left Depth: " << left << " | Overall Depth: " << depth << " | Value: " << value << endl;
                node* newNode = createNode(value);
                prev->rightBranch = newNode;
                return head;
            }
        }
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

node* LinkedList::createNode(int value) {
    node* newNode = new node;
    newNode->keyValue = value;
    newNode->leftBranch = NULL;
    newNode->rightBranch = NULL;
    return newNode;
}