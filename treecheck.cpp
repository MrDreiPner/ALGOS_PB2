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
	cout << "\nPress any key to continue...";
	char input = _getch();
	system("cls");

	delete(Tree);
}