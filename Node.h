#pragma once

class Node
{
private:
	int key;
	//int value;
	Node *pLeft;
	Node *pRight;

public:
	Node(int key);
	Node* GetLeft();
	Node* GetRight();
	int GetKey() const;
	// vyhleda a vrati prvek s minimalni hodnotu ve stromu
	friend Node* Min(Node *pNode);
	// vyhleda a vrati prvek s maximalni hodnotu ve stromu
	friend Node* Max(Node *pNode);
	// vyhleda prvek podle klice ve stromu
	friend Node* Search(Node *pNode, int key);
	friend void printTreeInTreeForm(Node *node);
	friend class BST;
	friend class AVL;
};