#pragma once
#include "BST.h"

class AVL : public BST
{
private:
	int Balance(Node *pNode);
public: 
	int Balance();
};
