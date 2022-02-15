#include "ListBaseStack.h"
#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

BTreeNode* MakeExpTree(char exp[])
{
	Stack stack;
	BTreeNode* pnode;

	int expLen = strlen(exp);

	StackInit(&stack);

	for (int i = 0; i < expLen; i++)
	{
		pnode = MakeBTreeNode();
		if (isdigit(exp[i]))
		{
			SetData(pnode, exp[i] - '0');
		}
		else
		{
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}
		SPush(&stack, pnode);
	}
	return SPop(&stack);
}

void ShowNodeData(int data)
{
	if (0 <= data && data <= 9)
		printf("%d ", data);
	else
		printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode* bt)
{
	PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode* bt)
{
	/*
	if (bt == NULL)
		return;
	if (!(bt->left == NULL && bt->right == NULL))
		printf("(");

	ShowInfixTypeExp(bt->left);
	if (0 <= GetData(bt) && GetData(bt) <= 9)
		printf("%d", GetData(bt));
	else
		printf("%c", GetData(bt));
	ShowInfixTypeExp(bt->right);
	if (!(bt->left == NULL && bt->right == NULL))
		printf(")");*/

	InorderTraverse(bt, ShowNodeData);
}

void ShowPostfixTypeExp(BTreeNode* bt)
{
	PostorderTraverse(bt, ShowNodeData);
}

int EvaluateExpTree(BTreeNode* bt)
{
	if (GetLeftSubTree(bt) == NULL && GetRighttSubTree(bt) == NULL)
		return GetData(bt);

	int op1 = EvaluateExpTree(GetLeftSubTree(bt));
	int op2 = EvaluateExpTree(GetRighttSubTree(bt));

	switch (GetData(bt))
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}

	return 0;
}