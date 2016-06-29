/*
************************************************************************
	Program: Graph.java

	Description: Undirected graph data type implemented using a
	symbol table whose keys are vertices (String) and values are
	sets of neighbors (e.g. SET of Strings).

	Constraints:
	------------

	- Parallel edges are not allowed
	- Self loops are allowed
	- Adjacency lists will store many different copies of the same
	  String.

	Reference: http://introcs.cs.princeton.edu/java/45graph/Graph.java.html

************************************************************************
************************************************************************
	Program Notes:
	-------------

	The Graph class represents an undirected graph of vertices(nodes) 
	with String names.

	Supported operations:
	- Add edge
	- Add vertex
	- Get all vertices
	- Iterate over all adjacent neighbors of a vertex
	- Check if a vertex exists
	- Check if an edge exists
	- Self-loops allowed; parallel edges discarded

************************************************************************
*/

// Graph Class

public class Graph
{
	// Private members

	private ST <String, SET<String>> st;	// symbol table: key = string vertex, value = set of neighboring vertices
	private int edges;						// Number of edges

	
}
