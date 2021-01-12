typedef unsigned int ElementType;

#ifndef _Graph_H
#define _Graph_H

struct GraphADT;
typedef struct GraphADT *PtrToGraph;
typedef PtrToGraph Graph;

Graph ConstructGraph(Graph graph, unsigned int V);
unsigned int GetNumberOfNodes(Graph G);
unsigned int GetNumberOfNodes(Graph G);
Graph AddEdge(Graph g, ElementType Start,ElementType End, int weight);
Graph RemoveEdge(Graph g, unsigned int i, unsigned int j);
unsigned int GetNumPredecessors(Graph g, ElementType node,ElementType V);
int *Predecessors(Graph g,ElementType node, ElementType V);
unsigned int GetNumSuccessors(Graph g, ElementType node, ElementType V);
int *Successors(Graph g, ElementType node, ElementType V);
void PrintAdjMatrix(Graph G);

#endif


