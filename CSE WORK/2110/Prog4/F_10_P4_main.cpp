// main entry point 
// template code provided by Yosvany Blanco
// modified for Group F program 4 submission
// dijkstra implemented by Group F
// main.cpp

#include "F_10_P4_tools.h"

int main(void)
{
	// continue loop while play is true
	bool play = true;
	Adj_Matrix my_mat;
	while(play)
	{
		std::string Line; // string to read line in
		std::cout << "cmd>";
		std::getline(std::cin, Line); // read line from screen
		if(Line.empty())
		{
			std::cout << "Didn't input anything try again!";
			std::cout << std::endl;
			std::cin.clear();
			continue;
		}
		std::vector<std::string> Parsed; // vector to store parsed words
		LineParser(Line, Parsed, false); // function to parse words into vector
		
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
		else if (Parsed[0] == "file")
		{
			if( Parsed.size() == 2)
			{
				FileRead(Parsed[1], my_mat);
			}
			else if (Parsed.size() > 2)
				std::cout << "You entered too many file names!" << std::endl;
			else
				std::cout << "It looks like you didn't enter any file name!" << std::endl;
			
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
		else if (Parsed[0] == "quit" || Parsed[0] == "exit")
		{//break the loop 
			play = false;
		}
		else if (Parsed[0] == "clear")
		{
			system("clear"); // for myself. force it to be "clear" hard coded instead of Parsed[0] just incase sneaky hackers try to hack my program
		}
		else
		{
			std::cout << "Invalid input try again." << std::endl;
		}
	}
return 0;	
}