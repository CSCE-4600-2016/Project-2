// This file will contain class and function declarations
// template code provided by Yosvany Blanco
// modified for Group F program 4 submission
//dijkstra implemented by Group F
// tools.h

//header includes
#include <iostream>
#include <iomanip> //setw
#include <string>
#include <vector> // for std::vector use
#include <sstream> // for std::stringstream
#include <fstream> // file io
#include <algorithm> //use to remove characters
#include <stack>
#define INF 99999
/////////////////
#ifndef TOOLS_H
#define TOOLS_H
//
extern const int difference;// this difference need to get a lowercase ascii letter to be a matrix index. so 'a' - 97 == 0
extern bool UNDIRECTED; // required by specification
// Class Declarations
struct Adj_Member
{
public:
	char Row; //will describe current row
	char Col; // will describe current collumn
	bool Connected; // will show if nodes are connected
	bool RowExists; // true if node exists
	bool ColExists;
	float distance;
	std::string label; //name of road
};

class Adj_Matrix
{
/*private:*/ // too lazy to do proper encapsulation right now
public:
	std::vector<std::vector<Adj_Member>> Position;// so we can get to member like so, mymatrix.Position[some number]
	std::vector<std::string> nodes; // vector of the nodes in the table
	
/*public:*/
	//will make 26x26 matrix by default
	Adj_Matrix(); //default constructor
	// class functions
	void AddNode(std::string Node, bool cond = true); //true by default
	void DelNode(std::string Node); //will be a wrapper function of AddNode(Node, false)
	void AddEdge(std::string Node1, std::string Node2, std::string label, float distance, bool kruskalmode = false);
	void DelEdge(std::string Node1, std::string Node2);
	void PrintMat(void);
	void PrintList(void);
	bool Searchnodes(std::string Node);
	void Kruskal();
	void Dijkstra(std::string startnode, std::string endnode);
	void dij_help(char row, char col);
	// class functions
	// we'll let c++ handle deletion of this object
};

///////////////////
///////////////////
// Function Declarations

// pass in a reference to an empty string vector that will be used to parse passed in Line
// bool CSV true for CSV parse mode // CSV will be set to false by default
void LineParser(const std::string Line, std::vector<std::string> &Holder, bool CSV = false);
// will use this to make parsed words lowercase
void MakeVectLower(std::vector<std::string> &Holder);
void CheckParsed(std::vector<std::string> &Holder);
////////////////////////////////////////////////////////////////////////////////
//input handling
void myNodeHandle(const std::vector<std::string> &Parsed, class Adj_Matrix &my_mat); // if first word is NODE
void myEdgeHandle(const std::vector<std::string> &Parsed, class Adj_Matrix &my_mat);
void FileRead(std::string FilePath, class Adj_Matrix &my_mat);
bool searchset(char start, char end, std::vector<std::vector<char>> &sets);
//////////extra tools//////////////
int mindist( float dist[], bool shortest[], int size);
///////////////////////
#endif