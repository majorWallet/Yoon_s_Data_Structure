#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque* pdeq)
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int DQIsEmpty(Deque* pdeq)
{
	return (pdeq->head == NULL || pdeq->tail == NULL ? TRUE : FALSE);
}

void DQAddFirst(Deque* pdeq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pdeq->head;
	newNode->prev = NULL;
	if (pdeq->tail == NULL)
		pdeq->tail = newNode;
	if (pdeq->head != NULL)
		pdeq->head->prev = newNode;
	pdeq->head = newNode;
}

void DQAddLast(Deque* pdeq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = pdeq->tail;
	if (pdeq->head == NULL)
		pdeq->head = newNode;
	if (pdeq->tail != NULL)
		pdeq->tail->next = newNode;
	pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque* pdeq)
{
	Node* rNode = pdeq->head;
	Data rData = rNode->data;

	if (DQIsEmpty(pdeq))
	{
		printf("Deque memory error!");
		exit(100);
	}

	pdeq->head = pdeq->head->next;
	if(pdeq->head != NULL)
		pdeq->head->prev = NULL;
	free(rNode);
	return rData;
}

Data DQRemoveLast(Deque* pdeq)
{
	Node* rNode = pdeq->tail;
	Data rData = rNode->data;

	if (DQIsEmpty(pdeq))
	{
		printf("Deque memory error!");
		exit(100);
	}

	pdeq->tail = pdeq->tail->prev;
	if (pdeq->tail != NULL)
		pdeq->tail->next = NULL;
	free(rNode);
	return rData;
}

Data DQGetFirst(Deque* pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Deque memory error!");
		exit(100);
	}

	return pdeq->head->data;
}

Data DQGetLast(Deque* pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Deque memory error!");
		exit(100);
	}

	return pdeq->tail->data;
}