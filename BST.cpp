#include "stdafx.h"
#include "BST.h"

BST::BST()
{
	pRoot = NULL;
}

void deleteNodes(Node* node) {
	if (node != NULL) {
		deleteNodes(node->GetLeft());
		deleteNodes(node->GetRight());
		delete node;
	}
}

BST::~BST()
{
	deleteNodes(pRoot);
	pRoot = NULL;
}

Node *BST::GetRoot()
{
	return pRoot;
}

void BST::insert(int key)
{
	// Vytvor uzel stromu s hodnotou key. A zarad uzel do stromu tak, aby se vytvarel binarni "vyhledavaci" strom.
	//
	if (pRoot == NULL)
		pRoot = new Node(key);
	else
	{
		Node *pTmp = pRoot, *pTmpPrev = NULL;
		if (key == pTmp->key)
			return;
		else
		{
			// hledani listu stromu (podle pravidel BVS)
			do
			{
				pTmpPrev = pTmp;
				if (key < pTmp->key)
					pTmp = pTmp->pLeft;
				else
					pTmp = pTmp->pRight;
			} while (pTmp != NULL);

			// vlozeni noveho uzlu jako potomka listu stromu
			if (key < pTmpPrev->key)
				pTmpPrev->pLeft = new Node(key);
			else
				pTmpPrev->pRight = new Node(key);

		}
	}
}

Node* BST::Search(int key)
{
	return ::Search(pRoot, key);
}

Node* BST::Parent(Node *pNode)
{
	// Hledej na ceste od korene stromu ke hledanemu uzlu. 
	if (pNode == pRoot)
		return NULL;

	Node *pTmp = pRoot, *pTmpPrev = NULL;
	// todo: nalezeni rodice uzlu pNode
	do
	{
		pTmpPrev = pTmp;
		if (pTmp->key > pNode->key)
			pTmp = pTmp->pLeft;
		else
			pTmp = pTmp->pRight;
	} while ((pTmp != pNode) && (pTmp != NULL));

	if (pTmp == NULL)
		return NULL;
	return pTmpPrev;
}

Node* BST::Prec(Node *pNode)
{
	return ::Max(pNode->pLeft);
}

Node* BST::Succ(Node *pNode)
{
	return ::Min(pNode->pRight);
}

bool BST::Contain(int key)
{
	return !(::Search(pRoot, key) == NULL);
}

// -----------------------------------

#define MAX_INT(x, y) ((x) > (y) ? x : y);

/* protected */ int BST::Height(Node *pNode)
{
	if (pNode == NULL)
		return 0;
	return 1 + MAX_INT(Height(pNode->pLeft), Height(pNode->pRight));
}

int BST::Height()
{
	if (pRoot == NULL)
		return -1;
	return Height(pRoot);
}

void BST::Del(Node *pNode)
{
	if (pNode == NULL)
		return;

	if (pNode->pLeft == NULL && pNode->pRight == NULL)
	{
		Node* pParent = Parent(pNode);
		if (pParent == NULL)
		{
			delete pNode;
			pRoot = NULL;
		}
		else if (pParent->pLeft == pNode)
			pParent->pLeft = NULL;
		else
			pParent->pRight = NULL;

		delete pNode;
		return;
	}

	if (pNode->pLeft == NULL || pNode->pRight == NULL)
	{
		Node* pParent = Parent(pNode), * x;
		if (pNode->pLeft)
			x = pNode->pLeft;
		else
			x = pNode->pRight;

		if (pParent == NULL)
			pRoot = x;
		else
			(pParent->pLeft == pNode) ? pParent->pLeft = x : pParent->pRight = x;

		delete pNode;
		return;
	}

	// prepis
	Node* y = Succ(pNode);
	Node* z = Parent(y);

	if (z != pNode) {
		z->pLeft = y->pRight;
		y->pRight = pNode->pRight;
	}

	y->pLeft = pNode->pLeft;
	pNode->key = y->key;

	delete y;
}