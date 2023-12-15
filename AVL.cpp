#include "stdafx.h"
#include "AVL.h"

int AVL::Balance(Node *pNode)
{
	if (pNode == NULL)
		return 0;
	return Height(pNode->pLeft) - Height(pNode->pRight);
}

int AVL::Balance()
{
	return Balance(pRoot);
}

