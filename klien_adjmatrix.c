#include<stdio.h>
#include"adjmatrix.h"

int main(int argc, char*argv[]){
	int *predecessors,i,counter;
	Graph G=NULL;
	
	G=ConstructGraph(G,5);
	int V=GetNumberOfNodes(G);
	printf("Number of Nodes in Graph: %u\n\n",V);
	
	G=AddEdge(G,0,1,3);
	G=AddEdge(G,0,2,5);
	G=AddEdge(G,1,2,2);
	G=AddEdge(G,1,3,6);
	G=AddEdge(G,2,3,1);
	G=AddEdge(G,3,4,4);
	G=AddEdge(G,4,2,6);
	G=AddEdge(G,0,1,3);
	
	G=RemoveEdge(G,1,3);
	PrintAdjMatrix(G);
	
	counter=GetNumPredecessors(G,2,V);
	printf("\nnumber of predecessors of node 2= %u\n",counter);
	predecessors=Predecessors(G,2,V);
	printf("predecessors of node 2\n");
	for(i=0;i<counter;i++)
		printf("%d predecessors of node 2=%d\n",i+1,predecessors[i]);
	
	return 0;
}
