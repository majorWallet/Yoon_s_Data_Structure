#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table.h"

int MyHashFunc(int k)
{
	return k % 100;
}

int main()
{
	Table myTbl;
	Person* np;
	Person* sp;
	Person* rp;

	TBLInit(&myTbl, MyHashFunc);

	np = MakePersonData(900254, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(np), np);

	sp = MakePersonData(900139, "Kim", "Jeju");
	TBLInsert(&myTbl, GetSSN(sp), sp);

	rp = MakePersonData(900827, "Han", "Kangwon");
	TBLInsert(&myTbl, GetSSN(rp), rp);

	sp = TBLSearch(&myTbl, 900254);
	if (sp != NULL)
		ShowPerInfo(sp);

	sp = TBLSearch(&myTbl, 900139);
	if (sp != NULL)
		ShowPerInfo(sp);

	sp = TBLSearch(&myTbl, 900827);
	if (sp != NULL)
		ShowPerInfo(sp);

	rp = TBLDelete(&myTbl, 900254);
	if (sp != NULL)
		free(rp);

	rp = TBLDelete(&myTbl, 900139);
	if (sp != NULL)
		free(rp);

	rp = TBLDelete(&myTbl, 900827);
	if (sp != NULL)
		free(rp);

	return 0;
}