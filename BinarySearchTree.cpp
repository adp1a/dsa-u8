#include "stdafx.h"
#include <iostream>
#include "Node.h"
#include "BST.h"
using namespace std;

void printTreeInTreeForm(Node *node)
{
	if (node == NULL) {
		cout << "X";
		return;
	}

	cout << node->GetKey();

	if (node->GetRight() != NULL || node->GetLeft() != NULL) {
		cout << "(";
		printTreeInTreeForm(node->GetLeft());
		cout << ", ";
		printTreeInTreeForm(node->GetRight());
		cout << ")";
	} 
}

int _tmain(int argc, _TCHAR* argv[])
{
    BST t;

	t.insert(4);
	t.insert(8);
	t.insert(3);
	t.insert(5);
	t.insert(9);
	t.insert(7);

	// vypiš pomocí rekurze
	// vizualizace: https://www.cs.usfca.edu/~galles/visualization/BST.html
    printTreeInTreeForm(t.GetRoot());
	cout << endl << endl;

	t.Del(t.Search(3));
	t.Del(t.Search(4));

	printTreeInTreeForm(t.GetRoot());
	cout << endl << endl;

    return 0;
}