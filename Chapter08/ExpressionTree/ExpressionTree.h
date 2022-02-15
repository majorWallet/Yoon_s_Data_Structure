#ifndef __EXPRESSION__TREE_H__
#define __EXPRESSION__TREE_H__

#include "BinaryTree.h"

BTreeNode* MakeExpTree(char exp[]);
int EvaluateExpTree(BTreeNode* bt);

void ShowPrefixTypeExp(BTreeNode* bt);
void ShowInfixTypeExp(BTreeNode* bt);
void ShowPostfixTypeExp(BTreeNode* bt);

#endif