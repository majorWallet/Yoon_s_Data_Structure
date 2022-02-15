#ifndef __AL_GRAPH_H__
#define __AL_GRAPH_H__

#include "CircularQueue.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct ual
{
	int numV;
	int numE;
	Queue* adjList;
	int* visitInfo;
} ALGraph;

void GraphInit(ALGraph* pg, int nv);
void GraphDestroy(ALGraph* pg);
void AddEdge(ALGraph* pg, int fromV, int toV);
void ShowGraphEdgeInfo(ALGraph* pg);
void BFShowGraphVertex(ALGraph* pg, int startV);

#endif