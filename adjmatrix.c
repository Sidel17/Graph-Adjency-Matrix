#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "adjmatrix.h"

struct GraphADT{
	unsigned int V;
	unsigned int E;
	ElementType **adjmatrix;
};

Graph ConstructGraph(Graph graph,unsigned int V){
	int i,j;
	graph=malloc(sizeof(struct GraphADT));
	graph->V=V;
	graph->adjmatrix=(ElementType **)malloc(V*sizeof(ElementType *));
	if(graph->adjmatrix==NULL){
		printf("Memory is full");
		exit(1);
	}
	for(i=0;i<V;i++){
		graph->adjmatrix[i]=(ElementType *)malloc(V*sizeof(ElementType));
		if(graph->adjmatrix[i]==NULL){
			printf("Memory is full");
			exit(1);
			
		}
	}
	
	for(i=0;i<V;i++)
		for(j=0;j<V;j++){
			if(i==j)
				graph->adjmatrix[i][j]=0;
			else
				graph->adjmatrix[i][j]=UINT_MAX-1000;
			
		}
	return graph;
}

unsigned int GetNumberOfNodes(Graph g){
	return g->V;
}

unsigned int GetNumberOfEdges(Graph g){
	return g->E;
}

Graph AddEdge(Graph g,unsigned int i, unsigned int j,int weight){
	if(g!=NULL){
		g->adjmatrix[i][j]=weight;
		g->E++;

	}
	return g;
}

Graph RemoveEdge(Graph g, unsigned int i, unsigned int j){
	if(g!=NULL){
		g->adjmatrix[i][j]=UINT_MAX-1000;
		g->E--;
	}
	return g;
	
}

unsigned int GetNumPredecessors(Graph g,ElementType node, ElementType V){
	unsigned int i,counter=0;
	
	for(i=0;i<V;i++){
		if((g->adjmatrix[i][node]<UINT_MAX-1000)&&(i!=node))
			counter++;

	}
	return counter;
}

int *Predecessors(Graph g, ElementType node, ElementType V){
	int i=0,j=0, *predecessors;
	unsigned int counter=GetNumPredecessors(g,node,V);
	predecessors=malloc(counter*sizeof(unsigned int));
	for(i=0;i<V;i++){
		if((g->adjmatrix[i][node]<UINT_MAX-1000)&&(i!=node)){
			predecessors[j]=i;
			j++;
		}
	}
	return predecessors;
}

void PrintAdjMatrix(Graph g){
	int i,j;
	unsigned int V=GetNumberOfNodes(g);
	
	printf("\t");
	for(i=0;i<V;i++)
		printf(" V[%d]\t",i);
	printf("\n");
	for(i=0;i<V;i++){
		printf("V[%d]\t",i);
		for(j=0;j<V;j++){
			printf("%.10u\t", g->adjmatrix[i][j]);
		}
		printf("\n");
	}
}
