// treecheck.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include "LinkedList.h"

using namespace std;

int main(int argc, char* argv[])
{
				//Checking passed arguments
	cout << "You have entered " << argc << " arguments:" << "\n";
	for (int i = 0; i < argc; ++i)
		cout << argv[i] << "\n";
				//Creation of tree
	LinkedList* Tree = new LinkedList(argv[1]);
	int max = 0; int min = 0; double sum = 0; double count = 0; int avlCheck = 0;
	if (argc == 2) {
		Tree->checkBalance(Tree->getListHead(), sum, max, min, count, avlCheck);
		avlCheck == 0 ? cout << "AVL: yes" : cout << "AVL: no";
		cout << "\nmin: " << min << ", max: " << max << ", avg: " << sum / count << endl;
	}
	int treeFound = 0;
	if (argc > 2) {
		LinkedList* subtree = new LinkedList(argv[2]);
		Tree->subtreeSearch(subtree->getListHead(), Tree->getListHead(), treeFound);
		Tree->singleNodeSearch(subtree->getListHead(), Tree->getListHead());
		if (treeFound == 0)
			cout << "Subtree found!" << endl;
		else
			cout << "Subtree NOT found!" << endl;
		delete(subtree);
	}
	delete(Tree);
	cout << "\nPress any key to terminate program" << endl;
	char input = _getch();
	system("cls");
}