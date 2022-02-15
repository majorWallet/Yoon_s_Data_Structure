#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#define TRUE 1
#define FALSE 0

#define QUE_LEN 201

typedef int Data;

typedef struct cQueue
{
	int front;
	int rear;
	Data queArr[QUE_LEN];
} cQueue;

typedef cQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);

#endif