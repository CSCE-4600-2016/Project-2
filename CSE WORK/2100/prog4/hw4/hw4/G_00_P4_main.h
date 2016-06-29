/* written by Yosvany Blanco and group G
 * cse 2100 Burke summer 2015
 * program 4  )
 * main.h
 */
// this file requires BlaY_00_P3_main.cpp and BlaY_00_P3_functions.cpp to function
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

void menu(void);
int checkname(std::string);//function to make sure name only consists of letters
void fileread(class List& book);

struct Node {
	//node
	std::string person; // going to keep this name since alot of the code is written with person, just think of person as "lastname"
	std::string firstname;
	std::string address1;
	std::string city;
	std::string state;
	unsigned int zip;
	std::string birth;
	std::string death;
	std::string wedding;
	unsigned int id; // an unsigned int used to handle a persons id, it's unsigned becaue we don't need negative ints
	Node* next_;  // this creates the list
	std::vector < Node* > child; //vector of nodes used to handle the children a person might have
	Node* spouse; // a pointer to another member of the list this will be used to point to a person's spouse
};


class List {

private:
	Node* head_;
	Node* tail_; 
	int size;
	int idcount;
	//head node and tail node of list
public:
	List(void);
	//empty constructor tail and head set to null

	~List(void); //destructor to clear out linked list
		//don't need any memory leaks now
	void addname(std::string lastname, std::string firstname);

	void addspouse(unsigned int id, std::string lastname, std::string firstname);// the "id" being passed in is that of the person you're giving the spouse to, not the id of spouse.. obviously

	void addchild(unsigned int id, std::string lastname, std::string firstname);	

	void addaddress(unsigned int id, std::string address);

	void addcity(unsigned int id, std::string city);

	void addstate(unsigned int id, std::string state);

	void addzip(unsigned int id, unsigned int zip);

	void addbirth(unsigned int id, std::string birth);

	void addwedding(unsigned int id, std::string wedding);

	void adddeath(unsigned int id, std::string death);

	void print(void);//just prints uid and names of everyone in list

	void printinfo(std::string id); // this will print the info of a specific person

	void setsize(void);

	int getsize(void);

	void removename(std::string firstname, std::string lastname);

	unsigned int searchname(std::string lastname, std::string firstname);

  Node* nodesearch(unsigned int new_id);
};

class Tree{ //didn't bother with encapsulation here, it wasn't needed
public:
////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
  void treeprinthelp(Node* p)
  {
    int maxHeight = 3;
    int space = 65;
    //std::cout << "                                                            ";
    for(int i = 0;i<3;i++)
    {
      for(int s = 0 ; s < space; s++){std::cout << " ";}
        //formula to print initial number of spaces for the tree like structure
        //which will be dependant on the max allowed child nodes and the height of tree
        treeprint(p,i,0,0);
        std::cout<<'\n' << '\n';
        space -= (space/3);
    }
  }

  void treeprint(Node* root, int currLevel, int lvlPrint, int pos)
  {
    if(root==NULL)
    {
        std::cout<<'\t' << '\t';
        return;
    }
    if(currLevel == lvlPrint){// if tree traversal is a desired tree level/height then print the member
      if((currLevel == 0|| currLevel ==1) && root->spouse){//if the node is root and has a spouse
        std::cout<< '(' <<root->firstname + " " + root->person << ')' << "---spouse----> " << '(' << root->spouse->firstname + " " + root->spouse->person << ')' << '\t';
      }
    
      else{
        if(pos == 0 && currLevel != 0){
             std::cout << '/' ; //if the child node is a left child
        }
        else if (pos == 1 && currLevel != 0){
             std::cout << '|'; //if the child node is a middle child
        }
        else if(pos == 2 && currLevel != 0)
             std::cout << '\\'; //if the child node is a right child
        std::cout<< '(' <<root->firstname + " " + root->person << ')'; //print first and last name "person" is my variable for lastname
        if(currLevel == 1){
          for(int s = 0 ; s < 3; s++){
            std::cout << '\t' << "       ";
          }
        }
        else
          std::cout << '\t'; // prints a tab otherwise
      }
    }
    else
    {
        for(int i = 0 ; i < 3; i++) //iterate through all possible children
        {
          if(i >= root->child.size())
          {
            treeprint(NULL,currLevel, lvlPrint + 1, i);//recursive step
          }
          else{
             treeprint(root->child[i], currLevel, lvlPrint + 1, i); //recursive step

          }
        }
    }
  }
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
};
