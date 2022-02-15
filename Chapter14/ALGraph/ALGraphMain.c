#include <stdio.h>
#include "ALGraph.h"

int main()
{
	ALGraph graph;
	GraphInit(&graph, 5);

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, A, C);
	AddEdge(&graph, C, D);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, A);

	SHowGraphEdgeInfo(&graph);
	GraphDestroy(&graph);
	return 0;
}