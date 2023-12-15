#include "stdafx.h"
#include "Node.h"

Node::Node(int key)
{
	this->key = key;
	pLeft = NULL;
	pRight = NULL;
}

int Node::GetKey() const
{
	return key;
}

Node* Node::GetLeft()
{
	return pLeft;
}

Node* Node::GetRight()
{
	return pRight;
}

// ------------------------------------

/*friend*/ Node* Min(Node *pNode)
{
	if (pNode == NULL)
		return NULL;
	while (pNode->pLeft != NULL)
		pNode = pNode->pLeft;
	return pNode;
/*
	if (pNode == NULL)
		return NULL;
	if (pNode->pLeft != NULL)
		return Min(pNode->pLeft);
	return pNode;
	*/
}

/*friend*/ Node* Max(Node *pNode)
{
	if (pNode == NULL)
		return NULL;
	while (pNode->pRight != NULL)
		pNode = pNode->pRight;
	return pNode;
}

/*friend*/ Node* Search(Node *pNode, int key)
{
	if (pNode == NULL)
		return NULL;  // hledana hodnota (uzel s hledanou hodnotou) ve strome neexistuje
	if (pNode->key == key)
		return pNode;
	if (pNode->key > key)
		return Search(pNode->pLeft, key);
	else
		return Search(pNode->pRight, key);    
	/*
	while ((pNode != NULL) && (pNode->key != key))
	{
		if (pNode->key > key)
			pNode = pNode->pLeft;
		else
			pNode = pNode->pRight;
	}
	return pNode;
	*/
}
