#include <stdio.h>
#include <string.h>
#include "UsefulHeap.h"
#include "PriorityQueue.h"

int DataPriorityComp(HData ch1, HData ch2)
{
	return strlen(ch1) - strlen(ch2);
}

int main()
{
	PQueue pq;
	HeapInit(&pq, DataPriorityComp);

	HInsert(&pq, "AA");
	HInsert(&pq, "BBB");
	HInsert(&pq, "CCCC");

	HInsert(&pq, "AA");
	HInsert(&pq, "BBB");
	HInsert(&pq, "CCCC");

	while (!HIsEmpty(&pq))
		printf("%s\n", HDelete(&pq));

	return 0;
}