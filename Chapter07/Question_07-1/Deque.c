#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Queue* pdeq)
{
	pdeq->front = NULL;
	pdeq->rear = NULL;
}

int DQIsEmpty(Queue* pdeq)
{
	return (pdeq->front == NULL || pdeq->rear == NULL ? TRUE : FALSE);
}

void DQAddFirst(Queue* pdeq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pdeq->front;
	newNode->prev = NULL;
	if (pdeq->rear == NULL)
		pdeq->rear = newNode;
	if (pdeq->front != NULL)
		pdeq->front->prev = newNode;
	pdeq->front = newNode;
}

void DQAddLast(Queue* pdeq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = pdeq->rear;
	if (pdeq->front == NULL)
		pdeq->front = newNode;
	if (pdeq->rear != NULL)
		pdeq->rear->next = newNode;
	pdeq->rear = newNode;
}

Data DQRemoveFirst(Queue* pdeq)
{
	Node* rNode = pdeq->front;
	Data rData = rNode->data;

	if (DQIsEmpty(pdeq))
	{
		printf("Deque memory error!");
		exit(100);
	}

	pdeq->front = pdeq->front->next;
	if(pdeq->front != NULL)
		pdeq->front->prev = NULL;
	free(rNode);
	return rData;
}

Data DQRemoveLast(Queue* pdeq)
{
	Node* rNode = pdeq->rear;
	Data rData = rNode->data;

	if (DQIsEmpty(pdeq))
	{
		printf("Deque memory error!");
		exit(100);
	}

	pdeq->rear = pdeq->rear->prev;
	if (pdeq->rear != NULL)
		pdeq->rear->next = NULL;
	free(rNode);
	return rData;
}

Data DQGetFirst(Queue* pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Deque memory error!");
		exit(100);
	}

	return pdeq->front->data;
}

Data DQGetLast(Queue* pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Deque memory error!");
		exit(100);
	}

	return pdeq->rear->data;
}