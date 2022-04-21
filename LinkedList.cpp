#include <iostream>
#include <fstream>
#include <string.h>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(char* passedFileName) {
	struct node* head = new node;
	head = NULL;
    ifstream file;
                //append .txt to input
    string filename = passedFileName;
    filename = filename + ".txt";
    std::cout << "Control: " << filename << endl;
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
    while (file >> value) {
        append(head, value);
    }
    file.close();
}

LinkedList::~LinkedList() {
    std::cout << "Tree deleted\n";
}

node* LinkedList::append(struct node* head, int value) {
    node* current = head;
    node* prev = NULL;
    int left = 0;
    int right = 0;
    int depth = 0;
    int steps = 0;
    std::cout << "Value: " << value << " | ";
                //Root creation
    if (head == NULL) {
        std::cout << "Root depth: 0" << endl;
        node* newNode = createNode(value);
        return newNode;
    }
    while (current != NULL) {
        ++steps;
                //Throwing away value if already present in tree.
        if (value == current->keyValue) {
            std::cout << " FAIL! Duplicate found -> Value: " << value << " has been dropped!" << endl;
            break;
        }
                //smaller value are appended to the left branch/ bigger ti the right branch
        else if (value < current->keyValue) {
            prev = current;
            current = current->leftBranch;
            std::cout << "L->";
            ++depth;
            ++left;
            if (current == NULL) {
                std::cout << " Done! --> Right depth: " << right << " | Left Depth: " << left << " | Overall Steps: " << steps << " | Depth: " << depth << endl;
                node* newNode = createNode(value);
                prev->leftBranch = newNode;
                return head;
            }
        }
        else {
            prev = current;
            current = current->rightBranch;
            std::cout << "R->";
            ++depth;
            ++right;
            if (current == NULL) {
                std::cout << " Done! --> Right depth: " << right << " | Left Depth: " << left << " | Overall Steps: " << steps << " | Depth: " << depth << endl;
                node* newNode = createNode(value);
                prev->rightBranch = newNode;
                return head;
            }
        }
    }
}

node* LinkedList::createNode(int value) {
    node* newNode = new node;
    newNode->keyValue = value;
    newNode->leftBranch = NULL;
    newNode->rightBranch = NULL;
    return newNode;
}

void LinkedList::checkBalance(node* knoten) {
    //recursive checking of balance
    int leftDepth = 0;
    int rightDepth = 0;
    int knotenValue = knoten->keyValue;
    cout << "Node " << knotenValue << " is getting checked." << endl;
    node* leftCurrent = knoten->leftBranch;
    node* rightCurrent = knoten->rightBranch;
    if (leftCurrent != NULL) {
        checkBalance(leftCurrent);
    }
    if (rightCurrent != NULL) {
        checkBalance(rightCurrent);
    }

    if (leftCurrent != NULL) {
        checkChild(leftCurrent, leftDepth);
    }
    if (rightCurrent != NULL) {
        checkChild(rightCurrent, rightDepth);
    }
    int diff = rightDepth - leftDepth;
    if (diff <= 1 && diff >= -1) {
        cout << "Node " << knotenValue << " is AVL balanced... as all things should be. Balance value = " << diff << endl;
    }
    else {
        cout << "Node " << knotenValue << " is NOT AVL balanced! Balance value = " << diff << endl;
    }
    return;
}

void LinkedList::checkChild(node* knoten, int& topDepth) {
    node* leftCurrent = knoten->leftBranch;
    node* rightCurrent = knoten->rightBranch;
    ++topDepth;
    if (leftCurrent != NULL && rightCurrent != NULL){
        --topDepth;
    }
    if (leftCurrent != NULL) {
        checkChild(leftCurrent, topDepth);
    }
    if (rightCurrent != NULL) {
        checkChild(rightCurrent, topDepth);
    }
    return;
}

void LinkedList::singleNodeSearch(node* subtree, node* current){
    node* sub = subtree;
    if (sub->leftBranch != NULL || sub->rightBranch != NULL) {
        return;
    }
    if (current != NULL) {
        if (checkNode(current, sub) == false) {
            sub->keyValue < current->keyValue ? singleNodeSearch(sub, current->leftBranch) : singleNodeSearch(sub, current->rightBranch);
        }
        else {
            current = this->listHead;
            cout << sub->keyValue << " found ";
            traverse(sub->keyValue, current);
            cout << "\n";
            return;
        }
    }
    else { cout << sub->keyValue << " not found!" << endl; }
}

bool LinkedList::checkNode(node* prime, node* sub){
    if (prime->keyValue == sub->keyValue) {
        return true;
    }
    return false;
}

void LinkedList::subtreeSearch(node* subtree, node* current) {
    node* sub = subtree;
    node* newRoot = current;
    while (newRoot != NULL) {
        if (checkNode(newRoot, sub) == false) {
            sub->keyValue < newRoot->keyValue ? newRoot = newRoot->leftBranch : newRoot = newRoot->rightBranch;
        }
        else if (checkNode(newRoot, sub) == true) { break; }
    }
    if (newRoot == NULL) {
        cout << "Subtree not found!" << endl;
        return;
    }
    if (sub->leftBranch != NULL && newRoot->leftBranch != NULL) {
        subtreeSearch(sub->leftBranch, newRoot->leftBranch);
    }
    else if (sub->rightBranch != NULL && newRoot->rightBranch != NULL) {
        subtreeSearch(sub->rightBranch, newRoot->rightBranch);
    }
    else {
        cout << "Subtree found" << endl;
    }
}

    void LinkedList::traverse(int num, node* current){
    if (current != NULL) {
        cout << current->keyValue << " ";
        if (current->keyValue == num) {
            return;
        }
        (current->keyValue > num) ? traverse(num, current->leftBranch) : traverse(num, current->rightBranch);
    }
}

