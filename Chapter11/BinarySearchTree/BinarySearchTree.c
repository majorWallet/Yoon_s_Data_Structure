#include <stdlib.h>
#include "BinaryTree.h"
#include "BinarySearchTree2.h"

void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode* bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode** pRoot, BSTData data)
{
	BTreeNode* pNode = NULL;  //parent Node
	BTreeNode* cNode = *pRoot;  //current Node, initialize cNode as rootNode
	BTreeNode* nNode = NULL;  //new Node
	while (cNode != NULL)  //cNode가 마지막에 도달하면, cNode에는 NULL이 저장됨.(append BinaryTree.c)
	{
		pNode = cNode;
		if (data == cNode->data)
			return;
		else if (data < cNode->data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRighttSubTree(cNode);
	}
	nNode = MakeBTreeNode();
	SetData(nNode, data);
	if (pNode != NULL)
	{
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else
		*pRoot = nNode;
}

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
	BTreeNode* cNode = bst;

	while (cNode != NULL)
	{
		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else if (target > GetData(cNode))
			cNode = GetRighttSubTree(cNode);
		else
			break;
	}
	return cNode;
}