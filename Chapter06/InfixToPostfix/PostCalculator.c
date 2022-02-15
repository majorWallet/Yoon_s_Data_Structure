#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

int EvalRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	char tok, op1, op2;
	StackInit(&stack);
	for (int i = 0; i < expLen; i++)
	{
		tok = exp[i];
		if (isdigit(tok))
			SPush(&stack, atoi(&tok));
		else
		{
			op1 = SPop(&stack);
			op2 = SPop(&stack);
			switch (tok)
			{
			case '+':
				SPush(&stack, op2 + op1);
				break;
			case '-':
				SPush(&stack, op2 - op1);
				break;
			case '*':
				SPush(&stack, op2 * op1);
				break;
			case '/':
				SPush(&stack, op2 / op1);
				break;
			}
		}
	}
	return SPop(&stack);
}