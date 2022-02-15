#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

int GetOpPrec(char op)
{
	switch (op)
	{
	case '*':
	case '/':
		return 5;  //highst operation rank
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;  //lowest operation rank
	}

	return -1;  //unregistered operator
}

int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);
	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

void ConvToRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	char* convExp = (char*)malloc((expLen+1)*sizeof(char));

	int idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * expLen + 1);
	StackInit(&stack);

	for (int i = 0; i < expLen; i++)
	{
		tok = exp[i];
		if (isdigit(tok))
			convExp[idx++] = tok;
		else
		{
			switch (tok)
			{
			case '(':
				SPush(&stack, tok);
				break;

			case ')':
				while (1)
				{
					popOp = SPop(&stack);
					if (popOp == '(')
						break;
					convExp[idx++] = popOp;
				}
				break;

			case '+': case '-':
			case '*': case '/':
				while(!SIsEmpty(&stack) &&
						WhoPrecOp(SPeek(&stack), tok) >= 0)  //tok의 연산순위가 stack보다 더 낮으면 stack의 모든 연산자를 꺼냄
					convExp[idx++] = SPop(&stack);

				SPush(&stack, tok);
				break;
			}
		}
	}

	while(!SIsEmpty(&stack))
		convExp[idx++] = SPop(&stack);

	strcpy(exp, convExp);
	free(convExp);
}