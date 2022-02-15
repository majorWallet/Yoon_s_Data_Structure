#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "CircularQueue.h"

enum {CHEESE = 0, BULGOGI = 1, DOUBLE = 2};

int main()
{
	Queue waiting;
	QueueInit(&waiting);

	int Ltime = 0;
	int chkOrdTime = 0;
	int cntMenu[3] = { 0, };
	int menu = 0;

	srand(time(NULL));

	while (Ltime < 3600)
	{
		if (Ltime % 15 == 0)
		{
			menu = rand() % 3;
			switch (menu)
			{
			case CHEESE:
				Enqueue(&waiting, menu);
				chkOrdTime = Ltime + 12;
				cntMenu[CHEESE] += 1;
				break;
			case BULGOGI:
				Enqueue(&waiting, menu);
				chkOrdTime = Ltime + 15;
				cntMenu[BULGOGI] += 1;
				break;
			case DOUBLE:
				Enqueue(&waiting, menu);
				chkOrdTime = Ltime + 24;
				cntMenu[DOUBLE] += 1;
				break;
			}
		}
		if (!QIsEmpty(&waiting))
		{
			if (Ltime == chkOrdTime && QPeek(&waiting) == CHEESE)
				Dequeue(&waiting);
			else if (Ltime == chkOrdTime && QPeek(&waiting) == BULGOGI)
				Dequeue(&waiting);
			else if (Ltime == chkOrdTime && QPeek(&waiting) == DOUBLE)
				Dequeue(&waiting);
		}
		Ltime++;
	}

	printf("치즈버거: %d\n", cntMenu[CHEESE]);
	printf("불고기버거: %d\n", cntMenu[BULGOGI]);
	printf("더블버거: %d\n", cntMenu[DOUBLE]);
}