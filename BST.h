#pragma once
#include "Node.h"

class BST
{
protected:
	Node *pRoot;
	int Height(Node *pNode);

public:
	BST();
	~BST();
	// vrati koren stromu
	Node *GetRoot();
	// vlozi prvek s klicem do stromu
	void insert(int key);
	// vyhleda prvek stromu podle klice
	Node* Search(int key);
	// urci rodicovsky uzel daneho uzlu
	Node* Parent(Node *pNode);
	// urci bezprostredniho predchudce uzlu 
	Node* Prec(Node *pNode);
	// urci bezprostredniho naslednika uzlu
	Node* Succ(Node *pNode);
	// otestuje, jestli ve stromu existuje uzel s klicem
	bool Contain(int key);
	// hloubka stromu
	int Height();
	// odstraní uzel ze stromu
	void Del(Node *pNode);
};