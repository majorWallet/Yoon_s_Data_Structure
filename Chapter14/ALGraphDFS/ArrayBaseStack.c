#include <stdlib.h>
#include <stdio.h>
#include "ArrayBaseStack.h"

void StackInit(Stack* pstack)
{
	pstack->topIndex = -1;
}

int SIsEmpty(Stack* pstack)
{
	return (pstack->topIndex == -1 ? TRUE : FALSE);
}

void SPush(Stack* pstack, Data data)
{
	(pstack->topIndex)++;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack* pstack)
{
	int rIdx;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(100);
	}

	rIdx = pstack->topIndex;
	(pstack->topIndex)--;

	return pstack->stackArr[rIdx];
}

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(100);
	}

	return pstack->stackArr[pstack->topIndex];
}