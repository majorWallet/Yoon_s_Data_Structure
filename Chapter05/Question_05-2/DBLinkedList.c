#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List* plist)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->prev = NULL;
	plist->head = newNode;
	plist->tail = newNode;
	plist->cur = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	/*
	newNode->next = plist->head;
	if (plist->head != NULL)
		plist->head->prev = newNode;

	newNode->prev = NULL;
	plist->head = newNode;
	*/

	plist->tail->next = newNode;
	newNode->prev = plist->tail;
	plist->tail = newNode;

	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata)
{
	if (plist->head->next == NULL)
		return FALSE;
	else
	{
		plist->cur = plist->head->next;
		*pdata = plist->cur->data;
		return TRUE;
	}
}

int LNext(List* plist, Data* pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;
	else
	{
		plist->cur = plist->cur->next;
		*pdata = plist->cur->data;
		return TRUE;
	}
}

int LPrevious(List* plist, Data* pdata)
{
	if (plist->cur->prev == plist->head)
		return FALSE;
	else
	{
		plist->cur = plist->cur->prev;
		*pdata = plist->cur->data;
		return TRUE;
	}
}

Data LRemove(List* plist)
{
	Data rData = plist->cur->data;
	Node* rNode = plist->cur;
	if (plist->cur != plist->tail)
	{
		rNode->prev->next = rNode->next;
		rNode->next->prev = rNode->prev;
		plist->cur = rNode->prev;
		free(rNode);
	}
	else
	{
		rNode->prev->next = NULL;
		plist->cur = rNode->prev;
		plist->tail = rNode->prev;
		free(rNode);
	}
	return rData;
}

int LCount(List* plist)
{
	return plist->numOfData;
}