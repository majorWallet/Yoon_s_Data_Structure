#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct node
{
	Data data;
	struct node* next;
	struct node* prev;
} Node;

typedef struct queue
{
	Node* front;
	Node* rear;
} Queue;

typedef Queue Queue;

void DequeInit(Queue* pdeq);
int DQIsEmpty(Queue* pdeq);

void DQAddFirst(Queue* pdeq, Data data);
void DQAddLast(Queue* pdeq, Data data);

Data DQRemoveFirst(Queue* pdeq);
Data DQRemoveLast(Queue* pdeq);

Data DQGetFirst(Queue* pdeq);
Data DQGetLast(Queue* pdeq);

#endif