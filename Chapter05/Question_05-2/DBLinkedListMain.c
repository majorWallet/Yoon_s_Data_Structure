#include <stdio.h>
#include "DBLinkedList.h"

int main()
{
	List list;
	Data data;
	ListInit(&list);

	for (int i = 1; i < 9; i++)
	{
		LInsert(&list, i);
	}

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	if (LFirst(&list, &data))
	{
		if (data == 8)
			LRemove(&list);

		while (LNext(&list, &data))
			if (data == 8)
				LRemove(&list);
	}

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	return 0;
}