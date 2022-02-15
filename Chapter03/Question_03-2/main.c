#include <stdio.h>
#include "ArrayList.h"
#include "NameCard.h"

int main()
{
	List list;
	NameCard* nc;

	ListInit(&list);

	LInsert(&list, MakeNameCard("AA", "00"));
	LInsert(&list, MakeNameCard("BB", "01"));
	LInsert(&list, MakeNameCard("CC", "02"));

	if (LFirst(&list, &nc))
	{
		if (!NameCompare(nc, "CC"))
			ShowNameCardInfo(nc);

		while (LNext(&list, &nc))
			if (!NameCompare(nc, "CC"))
				ShowNameCardInfo(nc);
	}
	printf("\n");
	
	if (LFirst(&list, &nc))
	{
		if (!NameCompare(nc, "BB"))
			ChangePhoneNum(nc, "FuckPNum");

		while (LNext(&list, &nc))
			if (!NameCompare(nc, "BB"))
				ChangePhoneNum(nc, "FuckPNum");
	}

	if (LFirst(&list, &nc))
	{
		if (!NameCompare(nc, "AA"))
			LRemove(&list);

		while (LNext(&list, &nc))
			if (!NameCompare(nc, "AA"))
				LRemove(&list);
	}

	if (LFirst(&list, &nc))
	{
		ShowNameCardInfo(nc);

		while (LNext(&list, &nc))
			ShowNameCardInfo(nc);
	}

	return 0;
}