#include <iostream>
#include <fstream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(char* passedFileName) {
	struct node* head = new node;
	head = NULL;
    char* filename;
    if (passedFileName != NULL) {
        filename = passedFileName;
    }
    else {
                //placeholder in case no arguments (filename) are passed when calling executable
        char placeHolder[] = { "FileNoOpen" };
        filename = placeHolder;
    }
    ifstream file;
    file.open(filename);
    if (!file) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }
    int value;
                //creation of Root
    file >> value;
    head = append(head, value);
                //saving head in class object
    listHead = head;
                //appending rest of file in tree
    while (file >> value)
    {
        append(head, value);
    }
    file.close();
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
                //Root creation
    if (head == NULL) {
        cout << "Root depth: 0 | Value: " << value << endl;
        node* newNode = createNode(value);
        return newNode;
    }
    while (current != NULL) {
        ++depth;
                //Throwing away value if already present in tree.
        if (value == current->keyValue) {
            cout << " FAIL! Duplicate found -> Value: " << value << " has been dropped!" << endl;
            break;
        }
                //smaller value are appended to the left branch/ bigger ti the right branch
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

void LinkedList::print() {
    system("cls");
    node* current = listHead;
    node* prevNode = NULL;
    int left = 0;
    int right = 0;
    while (current != NULL) {
        ++left;
        cout << "Left Branch: " << left << " | Value: " << current->keyValue << endl;
        if (current->leftBranch == nullptr) {
            cout << "End of left branch reached at depth: " << left << endl;
            current = prevNode->rightBranch;
        }
        prevNode = current;
        current = current->leftBranch;
    }
    current = listHead;
    while (current != NULL) {
        ++right;
        cout << "Right Branch: " << right << " | Value: " << current->keyValue << endl;
        if (current->rightBranch == nullptr) {
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