// Implementing Kruskal algorithm on a graph

// Libraries

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

// a structure representing a weighted edge in a graph

struct Edge
{
	int source, dest, weight;
};

// a structure representing a connected, undirected,
// weighted graph

struct Graph
{
	// V-> Number of vertices, E-> number of edges
	int V, E;

	Edge* edge;
};

// Creating a graph type w/ V vertices and E edges

struct Graph* createGraph(int V, int E)
{
	struct Graph* graph =
	(struct Graph*) malloc(sizeof(struct Graph));

	graph->V = V; 
	graph->E = E;

	graph->edge =
	(struct Edge*) malloc(graph->E * sizeof(struct Edge));

	return graph;

};

struct subset
{
	int parent;
	int rank;
};

// Util function to find set of an element i
// using path compression technique

int find(struct subset subsets[], int i)
{
	// find root and make root parent of i
	if(subsets[i].parent != i)
	   subsets[i].parent = find(subsets, subsets[i].parent);

	return subsets[i].parent; 
}





// Main
int main()
{

	return 0;
}
