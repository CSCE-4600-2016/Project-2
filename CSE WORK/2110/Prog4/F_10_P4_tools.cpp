// this file will contain class and function definitions
// template code provided by Yosvany Blanco
// modified for Group F program 4 submission
//dijkstra implemented by Group F
// tools.cpp

#include "F_10_P4_tools.h"
bool UNDIRECTED = true;
const int difference = 97;// this difference need to get a lowercase ascii letter to be a matrix index. so 'a' - 97 == 0
// this specific function was shared with teammates if they have a similar function I should be referenced.
void LineParser(std::string Line, std::vector<std::string> &Holder, bool CSV)
{
	if(CSV == false)
	{// not reading from csv file but from main
		// Turn Line into a stream for parsing
		std::stringstream ss;
		ss.str(Line);
		std::string temp;
		while(std::getline(ss, temp ,' '))
		{
			Holder.push_back(temp); // pushes back each word
			
		}
	}
	else
	{ // parsing commas
		std::stringstream ss;
		ss.str(Line);
		std::string temp;
		while(std::getline(ss, temp ,','))
		{
			Holder.push_back(temp); // pushes back each word
			
		}	
	}
	// set words to lower case
	MakeVectLower(Holder);
	CheckParsed(Holder);
}

void MakeVectLower(std::vector<std::string> &Holder)
{	// uses a for auto loop c++11 style must enable c++ 11
	for( auto word = Holder.begin() ; word != Holder.end(); word++)
	{// use a range for loop with iterators
		for( auto c = word->begin() ; c != word->end() ; c++ )
		{ // here we dereference "word" because word is an iterator NOT a string. To get the string a -> is needed
			if(isupper(*c))
			{ //must dereference iterators like pointers to see actual data
				*c = tolower(*c);
			}
		}
	}
}

void CheckParsed(std::vector<std::string> &Holder)
{
	
	for (auto it = Holder.begin(); it != Holder.end(); ++it)
	{
		it->erase(std::remove(it->begin(), it->end(), ' '), it->end()); // this will delete any possible spaces in lines read from file// and i guess from user input aswell
		it->erase(std::remove(it->begin(), it->end(), '\r'), it->end());// this will delete any possible \r that are known to be placed in files by windows
		// burke makes his csv files in windows so this is a safety measure.
		// I had this issue with his provided files over the summer.
	}

	// this will delete any spaces parsed by the parser because the user doesn't know how to type proper
	for (auto it = Holder.begin(); it != Holder.end(); )
	{
		if ( it->empty() )
		{
			Holder.erase(it);
			it = Holder.begin();
		}
		else
			++it;
	}
	// it will delete empty parsed words
}

void myNodeHandle(const std::vector<std::string> &Parsed, class Adj_Matrix &my_mat)
{
/////error Handling////////////////////////////////////////////////////////////////
	if(Parsed.size() < 3) // should have 3 parameters "node add a"
	{// if they didn't write anything after "node " or just not enough things after node
		std::cout << "Didn't input enough parameters try again!";
		std::cout << std::endl;
		return;
	}
	else
	{
		if(Parsed[2].size() > 2)
		{// node name is too long not just a letter
			std::cout << "Your node name is too long!";
			std::cout << std::endl;
			return;
		}
		else if(Parsed[2].size() < 2)
		{
			std::cout << "Your node name was too short!";
			std::cout << std::endl;
			return;
		}
	}
	if (! (Parsed[2][0] == 'n'))
	{
		std::cout << "Node name provided must start with N or n when inputting per specification, please try again." << std::endl;
		return;
	}
	if( !(Parsed[2][1] >= 'a' && Parsed[2][1] <= 'z'))
	{// if node provided isn't a - z
		std::cout << "Node provided is not NA - NZ" << std::endl;
		return;
	}
	std::string Node = Parsed[2]; // create the character for Node usage
/////error Handling////////////////////////////////////////////////////////////////
	if (Parsed[1] == "add")
	{ // if second string is add // then add that node
		//check if node is already in board
		if (my_mat.nodes.empty() || ! my_mat.Searchnodes(Node))
		{// if the node vector is empty or the node isn't found add the node to the matrix and the vector
			my_mat.AddNode(Node);
			my_mat.nodes.push_back(Node);
			std::cout << "ADDED: NODE " << Node <<std::endl;
		}
		else
			std::cout << "*** ERROR *** DUPLICATE NODE: " << Node << std::endl;
	}
	else if (Parsed[1] == "delete")
	{// if second string is delete // then delete the node
		//check to see if node even exists in list
		if(my_mat.Searchnodes(Node))
		{// if the node exist delete it
			my_mat.DelNode(Node);
			std::cout << "DELETED: NODE " << Node <<std::endl;
			for ( auto it = my_mat.nodes.begin(); it != my_mat.nodes.end(); ++it)
			{ // finds and deletes node from node vector
				if (*it == Node)
				{
					my_mat.nodes.erase(it); // delete that node from the vector of nodes
					break;
				}
			}
		}
		else
			std::cout << "***ERROR*** NODE NOT FOUND FOR DELETION: " << Node << std::endl;
	}
	else if (Parsed[1] == "search")
	{// if second string is search // then search for the node
		if(my_mat.Searchnodes(Node))
		{
			std::cout << "NODE " << Node << ": FOUND" << std::endl;
		}
		else
			std::cout << "NODE " << Node << ": NOT FOUND" << std::endl;
	}
	else
	{
		std::cout << "Invalide input!";
		std::cout << std::endl;
		return;
	}
}

void myEdgeHandle(const std::vector<std::string> &Parsed, class Adj_Matrix &my_mat)
{
	//error checking ////////////////////\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\///
	if (Parsed.size() != 4)
	{ // not enough parameters
		if (Parsed.size() != 6)
		{
			std::cout << "Didn't input enough parameters try again!";
			std::cout << std::endl;
			return;			
		}
	}
	else if (Parsed[2].size() > 2 || Parsed[3].size() > 2)
	{// if nodes aren't just letters
		std::cout << "Your node name is too long!";
		std::cout << std::endl;
		return; 
	}
	else if (!(Parsed[2][1] >= 'a' && Parsed[2][1] <= 'z'))
	{// if node provided isn't a - z
		std::cout << "Node provided is not A - Z" << std::endl;
		return;
	}
	std::string Node1 = Parsed[2], Node2 = Parsed[3];
	if ( !( my_mat.Searchnodes(Node1) ) && !( my_mat.Searchnodes(Node2) ) )
	{// if neither provided node exists
		std::cout << "*** ERROR *** NODE " << Node1 << ": NOT FOUND" << std::endl;
		std::cout << "*** ERROR *** NODE " << Node2 << ": NOT FOUND" << std::endl;
		return;
	}
	else if ( !( my_mat.Searchnodes(Node1)) )
	{// if only node 1 doesn't exist
		std::cout << "*** ERROR *** NODE " << Node1 << ": NOT FOUND" << std::endl;
		return;
	}
	else if (!( my_mat.Searchnodes(Node2) ))
	{// if only node 2 doesn't exist
		std::cout << "*** ERROR *** NODE " << Node2 << ": NOT FOUND" << std::endl;
		return;
	}
	//error checking ///////////////////////^^^^^^^^^^^^^^^^
	if (Parsed[1] == "add")
	{
		std::string label = Parsed[4];
		std::stringstream ss;
		ss.str(Parsed[5]); //the next three lines parse a number from a string using string stream
		float distance;
		ss >> distance;
		
		my_mat.AddEdge(Node1, Node2, label, distance);
	}
	else if (Parsed[1] == "delete")
	{
		my_mat.DelEdge(Node1, Node2);
	}
}

void FileRead(std::string FilePath, class Adj_Matrix &my_mat )
{
	std::ifstream ifile; //input file stream
	
	ifile.open(FilePath.c_str());
	
	if(! ifile.is_open()){ //if file not open exit function
		std::cout << "The file was not opened. Did you type the right name?" << std::endl;
		return;
	}
	
	std::string Line;
	//int i = 1; //this is for break point debugging
	while( std::getline(ifile, Line) ) // read line
	{
		/*if( i == 11)
		{// break point debugging
			//do nothing
		}*/
		if(Line.empty())
		{
			//ignore empty lines
			continue;
		}
		std::vector<std::string> Parsed; // vector to store parsed words
		LineParser(Line, Parsed, true); // function to parse words into vector
		
		if (Parsed[0] == "node")
		{ // send the parsed strings off to be handled by myNodeHandle()
			myNodeHandle(Parsed, my_mat);
		}
		else if (Parsed[0] == "edge")
		{
			myEdgeHandle(Parsed, my_mat);
		}
		else if (Parsed[0] == "print" && Parsed.size() == 2 && Parsed[1] == "matrix")
		{
			my_mat.PrintMat();
		}
		else if (Parsed[0] == "print" && Parsed.size() == 2 && Parsed[1] == "list")
		{
			my_mat.PrintList();
		}
		else if (Parsed[0] == "kruskal")
		{
			std::cout << std::setw(26) << std::setfill('-') << "-" << std::endl;
			my_mat.Kruskal();
			std::cout << std::setw(26) << std::setfill('-') << "-" << std::endl;
			std::cout << std::setfill(' ');
		}
		else if (Parsed[0] == "distance")
		{
			if (Parsed.size() != 3)
			{
				std::cout << "You either forgot to pass a node in, forgot to pass in both nodes, or typed way too many things." << std::endl;
				std::cout << "The proper format is as follows, distance NA NB. Thanks try again." << std::endl;
			}
			else
				my_mat.Dijkstra(Parsed[1], Parsed[2]);
		}	
		//++i;
	}
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// class functions
Adj_Matrix::Adj_Matrix()
{
	//make a matrix of 26x26 size
	char row, col;
	for(row = 'a'; !(row > 'z'); ++row)
	{
		std::vector<Adj_Member> temp_vect;
		for(col = 'a'; !(col > 'z'); ++col)
		{
			Adj_Member temp_mem; // temp Adj_member type for push_back
			temp_mem.Row = row; temp_mem.Col = col; // set column and row names
			temp_mem.Connected = temp_mem.RowExists = temp_mem.ColExists = false; // set existance to false
			temp_mem.distance = -1;
			temp_vect.push_back(temp_mem);
		}
		Position.push_back(temp_vect);
	}
}

void Adj_Matrix::AddNode(std::string Node, bool cond)
{// this will add a node to the adjacency matrix
	for (auto it = Position.begin(); it != Position.end(); ++it)
	{// loops through row of vector
		for( auto itt = it->begin(); itt != it->end(); ++itt)
		{ // loops through coll of vector
			if (itt->Row == Node[1] && itt->Col == Node[1])
			{ // if position is that where row and col are the same as the added node set both existance bools to true
				itt->RowExists = cond;
				itt->ColExists = cond;
				if (itt->Connected == true && cond == false)
				{// will delete edge if DelNode calls the function and a connection exists
					itt->Connected = cond;
					std::cout << "EDGE AUTO REMOVED BY NODE DELETION: n" << itt->Row << "-n" << itt->Col << std::endl;
				}
			}
			else if(itt->Row == Node[1]) // if just row set row to true
			{ //set the node to exist
				itt->RowExists = cond;
				if (itt->Connected && cond == false)
				{
					itt->Connected = cond;
					std::cout << "EDGE AUTO REMOVED BY NODE DELETION: n" << itt->Row << "-n" << itt->Col << std::endl;
				}
			}
			else if (itt->Col == Node[1])// if just col ^^^^^^^^^^
			{
				itt->ColExists = cond;
				if (itt->Connected && cond == false)
				{
					itt->Connected = cond;
					std::cout << "EDGE AUTO REMOVED BY NODE DELETION: n" << itt->Row << "-n" << itt->Col << std::endl;
				}
			}
		}
	}
}

void Adj_Matrix::DelNode(std::string Node)
{
	AddNode(Node, false); // wraper function that deletes node using the addNode function
}

void Adj_Matrix::AddEdge(std::string Node1, std::string Node2, std::string label, float distance, bool kruskalmode)
{
	if ( Searchnodes(Node1) && Searchnodes(Node2) )
	{// force a check that both nodes exist once again just incase
		// using ascii value i can find the actual position on the matrix of the nodes
		int myrow = (int)(Node1[1] - difference);
		int mycol = (int)(Node2[1] - difference);
		if(Position[myrow][mycol].Connected == true)
		{ // if that edge already exists tell the user
			if (!kruskalmode)
			{
				std::cout << "EDGE " << Node1 << "-" << Node2 << " and "<< Node1 << "-" << Node2 << " UPDATE: " << label << " DIST: " << distance <<std::endl;
			}
			Position[myrow][mycol].distance = Position[mycol][myrow].distance = distance;
			Position[myrow][mycol].label = Position[mycol][myrow].label = label;
		}
		else
		{// if the edge doesn't exist set it to existing both ways
			Position[myrow][mycol].Connected = Position[mycol][myrow].Connected = true;
			Position[myrow][mycol].distance = Position[mycol][myrow].distance = distance;
			Position[myrow][mycol].label = Position[mycol][myrow].label = label;
			if (!kruskalmode)
			{
				std::cout << "ADDED: EDGE " << Node1 << "-" << Node2 << " NAME: " << label << " DIST: " <<  distance << std::endl;
				std::cout << "ADDED: EDGE " << Node2 << "-" << Node1 << " NAME: " << label << " DIST: " <<  distance << std::endl;
			}
		}
	}
	
}

void Adj_Matrix::DelEdge(std::string Node1, std::string Node2)
{
	if ( Searchnodes(Node1) && Searchnodes(Node1) )
	{// force a check that both nodes exist once again just incase
		// using ascii value i can find the actual position on the matrix of the nodes
		int myrow = (int)(Node1[1] - difference);// difference is constant defined in tools.h
		int mycol = (int)(Node2[1] - difference);
		if(Position[myrow][mycol].Connected == false)
		{ // if that edge does not exists tell the user
			std::cout << "*** ERROR *** EDGE DOES NOT EXIST FOR DELETION: " << Node1 << "-" << Node2 << std::endl;
		}
		else
		{// if the edge doesn't exist set it to existing both ways
			Position[myrow][mycol].Connected = false; //only delete in the provided direction
			Position[myrow][mycol].distance = -1;
			Position[myrow][mycol].label = "";
			UNDIRECTED = false;// block kruskal algorithm usage 
			std::cout << "DELETED: EDGE " << Node1 << "-" << Node2 << std::endl;
		}
		
	}
	
}

bool Adj_Matrix::Searchnodes(std::string Node)
{
	if(nodes.empty())
	{
		return false;
	}
	else
	{
		for (auto it = nodes.begin(); it != nodes.end(); ++it)
		{ // loop through the nodes vector
			if (*it == Node)
			{// if the passed in node is in the vector then the node exists
				return true;
			}
		}
	}
}

void Adj_Matrix::PrintMat(void)
{ // just prints nodes inside the matrix that exist // does not print empty board members
	std::cout << "ADJACENCY MATRIX" << std::endl;
	std::cout <<"     ";
	for(auto temp = Position[0].begin(); temp != Position[0].end(); ++temp)
	{//iterates through collumns
		if(temp->ColExists)// prints the names of the collumns if the collumn exists
		{
			std::cout << "|     n" << temp->Col << "      |";
		}
	}
	std::cout << std::endl; //newline

	for(auto it = Position.begin(); it != Position.end(); ++it)
	{//loop through row
		auto temp = it->begin();
		if(temp->RowExists)
		{
			std::cout << "|n" << temp->Row << " |";
		}
		for(auto inner = it->begin(); inner != it->end(); ++inner)
		{// loop through collumn
				if (inner->RowExists && inner->ColExists)
				{
					std::cout << "|  " << std::setw(3) << (int)inner->distance << ", " << std::setw(4) << inner->label << "  |"; //cast the bool to an int
				}
		}
		if((*it)[0].RowExists)// if the row exists print a newline
			std::cout << std::endl;
	} // this function is setup to take a full 26x26 board with empty slots and only print the relevant slots
}

void Adj_Matrix::PrintList(void)
{// this will just print the matrix in list form
	std::cout << "ADJACENCY LIST" << std::endl;
	for (auto it = Position.begin(); it != Position.end(); ++it)
	{
		if ((*it)[0].RowExists)
		{ // if the row exists
			std::cout << "n" << (*it)[0].Row << "---> ";
			for( auto inner = it->begin(); inner != it->end(); ++inner)
			{ // print any connections that exist with that row if that row exists
				if ( inner->Connected)
				{
					std::cout << "n"<< inner->Col<<"(" << inner->distance << ", " << inner->label << ") ";
				}
			}
			std::cout << std::endl;
		}
	}
}

void Adj_Matrix::Kruskal()
{
	if (UNDIRECTED == false)
	{
		std::cout << "The graph isn't undirected Kruskal can no longer be used sorry." << std::endl;
		return;
	}
	class Adj_Matrix krus;
	std::vector<struct Adj_Member> Paths; //this will be used to sort the distances
	std::vector<std::vector<char>> setofsets; //a set of sets for finding cycles
	int offset = 1; //this will keep the matrix search to only the upper triangular portion
	// no need to search entire matrix if graph is undirected
	for ( auto outer = Position.begin() ; outer != Position.end(); ++outer )
	{
		if ((*outer)[0].RowExists)
		{
			//if the row exist then that node must exist, we'll add that node to it's own set in the vector of vectors
			// vector of vectors is pseudo set of sets
			char cstuff[3]; cstuff[2] = '\0';
			cstuff[0] = 'n'; cstuff[1] = (*outer)[0].Row;
			std::string test(cstuff);
			krus.AddNode(test);
			krus.nodes.push_back(test);
			std::vector<char> temp; //create a vector to pushback onto the outer vector
			temp.push_back((*outer)[0].Row);
			setofsets.push_back(temp); // now we have a set of sets
			for ( auto inner = outer->begin() + offset ; inner != outer->end() ; ++inner)
			{
				if (inner->Connected)
				{
					struct Adj_Member other_temp = {inner->Row, inner->Col, inner->Connected, inner->RowExists, inner->ColExists ,inner->distance, inner->label};
					Paths.push_back(other_temp);
					// at this point we are collecting the paths into a collection to be sorted
				}
			}
		}
		offset++;
	}
	
	// at this point the collection of paths has been made and needs to be sorted
	// also at this point we have multiple sets that will be used to check for cycles

	// going to use a simple bubble sort for the path sorting since the number of paths will always be relatively low in this assignment
	
	// don't use iterators here to avoid iterator position swapping
	for ( std::vector<struct Adj_Member>::size_type i = 0; i < Paths.size(); ++i)
	{
		for (std::vector<struct Adj_Member>::size_type j = i; j < Paths.size() - 1; ++j) // -1 keeps from going out of bounds never need to run a check on the last member
		{
			if (Paths[j].distance > Paths[j + 1].distance)
			{
				std::swap(Paths[j], Paths[j + 1]);
				//std::swap from algorithm header
			}
		}
	}
	// now we have a sorted path collection/array/set whatever you want to call it
	for (auto i = Paths.begin(); i != Paths.end(); ++i)
	{
		// we must check the sets to see if a cycle will be created
		if (searchset(i->Row, i->Col, setofsets))
		{// searchset also rearranges the sets
			continue; // don't add the path because it creates a cycle
		}
		else
		{
			char charstart[3]; charstart[0] = 'n'; charstart[2] = '\0';
			char charend[3]; charend[0] = 'n'; charend[2] = '\0';
			charstart[1] = i->Row; charend[1] = i->Col;
			std::string stringstart(charstart), stringend(charend);
			krus.AddEdge(stringstart, stringend, i->label, i->distance, true);
		}
	}
	std::cout << "MINIMAL SPANNING TREE" << std::endl;
	krus.PrintList();
	//krus.PrintMat(); //debug stuff
	return; //everything was succesful
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//this function is meant for kruskal's
bool searchset(char start, char end, std::vector<std::vector<char>> &sets)
{
	int endset;//set that holds end node position
	int startset; //the set that holds the start node position
	bool startfound = false, endfound = false;
	for (int i = 0; i < sets.size(); ++i)
	{
		for (int j = 0; j < sets[i].size(); ++j)
		{// here we search for the set that has the start node
			if (sets[i][j] == start)
			{
				startfound = true;
				startset = i;
			}
			else if (startfound) //found start in the current set stop searching
				break;
		}
		for (int j = 0; j < sets[i].size(); ++j)
		{// here we search for the set that has the end node
			if (sets[i][j] == end)
			{
				endfound = true;
				endset = i;
			}
			else if (endfound) //found end in the current set stop searching
				break;
		}
		if (startfound && endfound)
			break;
	}
	
	if ( startset == endset)
	{// they are in the same set so a cycle is going to be created
		return true; // it is true that a cycle will be created
	}
	else
	{
		if (sets[endset].size() > sets[startset].size())
		{// run a check to see which set we should merge the sets into always merge into the bigger set if both aren't equal size
			std::vector<char> temp; // create a vector for merging
			temp = sets[startset];
			sets[endset].insert(sets[endset].begin(), temp.begin(), temp.end());
			sets.erase(sets.begin() + startset); //remove the set that was just merged*/
			return false;
		}
		else
		{
			std::vector<char> temp; // create a vector for merging
			temp = sets[endset];
			sets[startset].insert(sets[startset].begin(), temp.begin(), temp.end() );
			sets.erase(sets.begin() + endset); //remove the set that was just merged
			return false; //a cycle won't be created
		}
	}
}

void Adj_Matrix::Dijkstra(std::string startnode, std::string endnode)
{

	bool quit = false;
	///error checking//////////////////////////////////////////////////////////////////////////
	if (this->nodes.empty())
	{
		std::cout << "Your graph is currently empty, try dijkstras again later when you actually make a graph." << std::endl;
		return;
	}
	
	if(!this->Searchnodes(startnode))
	{
		std::cout << "*** ERROR *** NODE DOES NOT EXIST: " << startnode << std::endl;
		quit = true;
	}
	if(!this->Searchnodes(endnode))
	{
		std::cout << "*** ERROR *** NODE DOES NOT EXIST: " << endnode << std::endl;
		quit = true;
	}
	
	if(quit)
		return;
	////////////////////////////////////////////////////////////////////////////////////////////////
	//quick bubble sort of the set to keep it in order 
	for ( std::vector<std::string>::size_type i = 0; i < this->nodes.size(); ++i)
	{
		for (std::vector<std::string>::size_type j = i; j < this->nodes.size() - 1; ++j) 
		{
			if (this->nodes[j][1] > this->nodes[j + 1][1])
			{
				std::swap(this->nodes[j], this->nodes[j + 1]);
				//std::swap from algorithm header
			}
		}
	}
	std::vector<std::string> graph_nodes = this->nodes; //set of all the nodes in the graph

	int arrsize = this->nodes.size();
	int startnode_index, endnode_index;
	
	//finding node position in node set
	for( int i = 0; i < arrsize; i++)
	{
		if (startnode == graph_nodes[i])
		{
			startnode_index = i;
		}
		else if (endnode == graph_nodes[i])
		{
			endnode_index = i;
		}
	}
	
	float myarray[arrsize][arrsize];
	//convert my array into a simpler array to use dijkstra on
	for(int i = 0, mat_i = 0; i < this->Position.size(); i++)
	{
		for(int j = 0, mat_j = 0; j < this->Position[i].size(); j++)
		{
			if (this->Position[i][j].ColExists && this->Position[i][i].RowExists)
			{
				if (this->Position[i][j].distance == -1)
				{
					myarray[mat_i][mat_j] = 0; // we don't want to use negative 1 in this algorithm
				}
				else
					myarray[mat_i][mat_j] = this->Position[i][j].distance;

				if(mat_j == (arrsize - 1))
				{
					mat_j = 0; mat_i++;
				}
				mat_j++;
			}
		}
	}
	//initialize the array we will impliment dijkstra on
	/*for(int i = 0; i < arrsize; i++)
	{
		for(int j = 0; j < arrsize; j++)
		{
			std::cout << myarray[i][j] << " ";			DEBUG
		}
		std::cout << std::endl;
	}*/
	
	float dist[arrsize];
	int prev[arrsize];
	bool shortest[arrsize];
	for(int i = 0; i < arrsize; i++)
	{
		dist[i] = INF;
		prev[i] = -1;
		shortest[i] = false;
	}
	
	dist[startnode_index] = 0; //source node for now
	int target = endnode_index;
	
	// start of actual algorithm stuff
	for( int cnt = 0; cnt < (arrsize - 1); cnt++)
	{
			int u = mindist(dist, shortest, arrsize);
			if( u == target) //this is added to stop the algorithm once end node is apart of the set
				break;
			shortest[u] = true;								//typical dijkstras implementation as per pseudo code provided by the wikipedia page for dijkstras
			
			for (int v = 0; v < arrsize; v++)
			{
				if (!shortest[v] && myarray[u][v] && dist[u] != INF && dist[u]+myarray[u][v] < dist[v])
				{
					dist[v] = dist[u] + myarray[u][v];
					prev[v] = u;
				}
			}
	}
	
	/*for (int i = 0; i < arrsize; i++)
	{
		printf("%d \t\t %f\n", i, dist[i]);			DEBUG
	}*.
	/*for (int i = 0; i < arrsize; i++)
	{
		std::cout << prev[i] << " ";				DEBUG
	}*/
	std::stack<int> path; //gonna use a stack to iterate backwards through the recursive set we created inside of prev[]
	int temp = endnode_index; //this could just be written recursively but I really don't feel like writing another function
	while(prev[temp] != -1) //stop once it equals negative one
	{
		path.push(temp);
		temp = prev[temp];
	} // bunch of print formatting to make it look clear and pretty
	std::cout << "-------------------" << std::endl;
	std::cout << "Path from " << graph_nodes[startnode_index] << " to " << graph_nodes[endnode_index] << " " <<"" << std::endl << std::endl;
	std::cout << graph_nodes[startnode_index] <<std::endl;
	int current = startnode_index, next;
	while(!path.empty())
	{
		next = path.top();
		//empty the stack out
		std::cout << "\\/\t"; this->dij_help(graph_nodes[current][1], graph_nodes[next][1]);
		std::cout << graph_nodes[next] << std::endl;
		current = next;
		path.pop();
	}
	std::cout << "(Total: "<< dist[endnode_index] << ")" << std::endl;
	std::cout << "-------------------" << std::endl;
	/*for(int i = 0; i < graph_nodes.size(); i++)
	{
		std::cout << graph_nodes[i] << " ";			DEBUG
	}
	std::cout << std::endl;*/
	
}

int mindist( float dist[], bool shortest[], int size)
{
	int min = INF, min_pos;
	
	for (int i = 0; i < size; i++)
	{
		if (shortest[i] == false && dist[i] <= min)
		{
			min = dist[i], min_pos = i;
		}
	}
	return min_pos;
}

void Adj_Matrix::dij_help(char row, char col)
{
	int num_row = row - difference, num_col = col - difference;
	
	std::cout << this->Position[num_row][num_col].label << " " << (int)this->Position[num_row][num_col].distance << std::endl;
}

















