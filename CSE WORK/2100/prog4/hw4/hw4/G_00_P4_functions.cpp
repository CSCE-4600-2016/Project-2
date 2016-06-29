/* written by Yosvany Blanco and group G
 * cse 2100 Burke summer 2015
 * program 4  
 * functions.cpp
 */
// this file requires BlaY_00_P3_main.h and BlaY_00_P3_main.cpp to function
#include "G_00_P4_main.h"
#include <stdlib.h>
#include <algorithm>
#include <sstream>
//methods//////////////////////////////////////////
List::List(void){
	head_ = tail_ = NULL;
	idcount = 1;
}// set head and tail to null when no arguments passed

void List::addname(std::string lastname, std::string firstname){ //this will add names already sorted into the list
	/////////////////////
	Node* otherwalker = head_;
	while (otherwalker){
		if (otherwalker->person == lastname && otherwalker->firstname == firstname){
			std::cout << "Duplicate: " << firstname << " " << lastname << std::endl << std::endl; //this will be removed in later programs duplicates will simply have different id and same name
			return;
		}
		otherwalker = otherwalker->next_;
	}
	////////////////////
	//add nodes to current list
	if (head_ == NULL){
		head_ = new struct Node;
		head_->person = lastname;
		head_->firstname = firstname;
		head_->id = idcount; //new stuff // unique id
    head_->spouse = NULL;
		idcount++;
		std::cout << "ADDED: ID"; 
    std::cout << std::setw(3) << std::setfill('0')<< head_->id;
    std::cout << " " << firstname << " " << lastname << std::endl; 
		head_->next_ = NULL;
		return;
	}
	//test stuff
	else{ //if name added is alphabetically before head, place infront of current head and make new head
		if (lastname.compare(head_->person) < 0){
			Node* temp = head_;
			Node* newhead = NULL;
			newhead = new struct Node;
			newhead->next_ = temp;
			head_ = newhead;
			head_->person = lastname;
			head_->firstname = firstname;
			head_->id = idcount; //new stuff// unique id
      head_->spouse = NULL;
			std::cout << "ADDED: ID"; 
      std::cout << std::setw(3) << std::setfill('0') << head_->id;
      std::cout << " " << firstname << " " << lastname << std::endl; 
			idcount++;
			return;
		}
	}
	Node* walker = head_;
	while(walker->next_ != NULL){
		if (lastname.compare(walker->next_->person) < 0){
			Node* newwalker = NULL;
			newwalker = new struct Node; //creates new node inbetween nodes if name is before current node
			newwalker->next_ = walker->next_;
			walker->next_ = newwalker;
			walker->next_->person = lastname;
			walker->next_->firstname = firstname;
			walker->next_->id = idcount;
      walker->next_->spouse = NULL;
			std::cout << "ADDED: ID"; 
      std::cout << std::setw(3) << std::setfill('0') << walker->next_->id;
      std::cout << " " << firstname << " " << lastname << std::endl; 
			idcount++;
			return;
		}
		else{
			walker = walker->next_;
		}
	}
	if(walker->next_ == NULL){ //adds same names or higher up names to end
		walker->next_ = new struct Node;
		walker = walker->next_;
		walker->person = lastname;
		walker->firstname = firstname;
		walker->id = idcount;
    walker->spouse = NULL;
		std::cout << "ADDED: ID"; 
    std::cout << std::setw(3) << std::setfill('0') << walker->id;
    std::cout << " " << firstname << " " << lastname << std::endl; 
		idcount++;
		walker->next_ = NULL;
	}
	tail_ = walker;
}

void List::addspouse(unsigned int id, std::string lastname, std::string firstname){
	unsigned int tempid;
	//std::cout << "ID passed in is " << id << std::endl; //debug
	if(tempid = searchname(lastname, firstname)){
		std::cout << "ALREADY IN LIST: " << lastname << " " << firstname << " " << "id: " << tempid << std::endl;
		Node* walker = head_;
		Node* spousepos; //position of spouse
		while(walker){
			//std::cout << walker->id << " " << tempid << std::endl; debug
			if(walker->id == tempid){
				spousepos = walker;
			}
			//std::cout << "this m8" << std::endl; debug
			walker = walker->next_;
		}
		walker = head_;
		while(walker){
			if(walker->id == id){
				walker->spouse = spousepos;
				spousepos->spouse = walker; // makes sure both spouses are linked both ways
				//std::cout << walker->spouse << std::endl; debug
			}
			//std::cout << "that m8" << std::endl; //debug
			walker = walker->next_;
		}
		return;
	}
	else{
		addname(lastname, firstname);
		tempid = searchname(lastname,firstname);
		Node* walker = head_;
		Node* spousepos; //position of spouse
		while(walker){
			if(walker->id == tempid){
				spousepos = walker;
			}
			walker = walker->next_;
		}
		walker = head_;
		while(walker){
			if(walker->id == id){
				walker->spouse = spousepos;
				spousepos->spouse = walker; // makes sure both spouses are linked both ways
				//std::cout << walker->spouse->firstname << "ayy bos" <<std::endl; // debug
			}
			walker = walker->next_;
		}
		//std::cout << "ADDED: " << firstname << " " << lastname << " " << tempid << std::endl; 
		return;
	}
}

void List::addchild(unsigned int id, std::string lastname, std::string firstname){
	unsigned int tempid;
	if(tempid = searchname(lastname, firstname)){
		std::cout << "ALREADY IN LIST: " << lastname << " " << firstname << " " << "id: " << tempid << std::endl;
		Node* walker = head_;
		Node* childpos; //position of child
		while(walker){ //walk through the list and match up the id of child that already exists in list
			if(walker->id == tempid){
				childpos = walker;
			}
			walker = walker->next_;
		}
		walker = head_;
		while(walker){
			if(walker->id == id){
				walker->child.push_back(childpos);
				if(walker->spouse){ // makes sure both spouses are linked to child, I'm assuming happy family here
					walker->spouse->child.push_back(childpos);
				}
			}
			walker = walker->next_;
		}
		return;
	}
	else{
		addname(lastname, firstname);
		tempid = searchname(lastname,firstname);
		Node* walker = head_;
		Node* childpos; //position of spouse
		while(walker){
			if(walker->id == tempid){
				childpos = walker;
			}
			walker = walker->next_;
		}
		walker = head_;
		while(walker){
			if(walker->id == id){
				walker->child.push_back(childpos);
				if(walker->spouse) // makes sure both spouses are linked both ways
				{
					walker->spouse->child.push_back(childpos);
				}
			}
			walker = walker->next_;
		}
		//std::cout << "ADDED: " << firstname << " " << lastname << " " << tempid << std::endl; 
		return;
	}
}

void List::addaddress(unsigned int id, std::string address){
	Node* walker = head_;
	while(walker){
		if(walker->id == id)
		{
			walker->address1 = address;
			//std::cout << walker->person << " " << walker->address1 << std::endl; //debug
			std::cout << "ADDED ADDRESS1: " << walker->address1 << " " << "UID:ID" << id << std::endl;
		}
		walker = walker->next_;
	}
}

void List::addcity(unsigned int id, std::string city){
	Node* walker = head_;
	while(walker){
		if(walker->id == id)
		{
			walker->city = city;
			//std::cout << walker->person << " " << walker->city << std::endl; //debug
			std::cout << "ADDED CITY: " << walker->city << " " << "UID:ID" << id << std::endl;
		}
		walker = walker->next_;
	}
}

void List::addstate(unsigned int id, std::string state){
	Node* walker = head_;
	while(walker){
		if(walker->id == id)
		{
			walker->state = state;
			//std::cout << walker->person << " " << walker->state << std::endl; //debug
			std::cout << "ADDED STATE: " << walker->state << " " << "UID:ID" << id << std::endl;
		}
		walker = walker->next_;
	}
}

void List::addzip(unsigned int id, unsigned int zip){
	Node* walker = head_;
	while(walker){
		if(walker->id == id)
		{
			walker->zip = zip;
			//std::cout << walker->person << " " << walker->zip << std::endl; //debug
			std::cout << "ADDED ZIP: " << walker->zip << " " << "UID:ID" << id << std::endl;
		}
		walker = walker->next_;
	}
}

void List::addbirth(unsigned int id, std::string birth){
	Node* walker = head_;
	while(walker){
		if(walker->id == id)
		{
			walker->birth = birth;
			//std::cout << walker->person << " " << walker->address1 << std::endl; //debug
			std::cout << "ADDED BIRTHDATE: " << walker->birth << " " << "UID:ID" << id << std::endl;
		}
		walker = walker->next_;
	}
}

void List::addwedding(unsigned int id, std::string wedding){
	Node* walker = head_;
	while(walker){
		if(walker->id == id)
		{
			walker->wedding = wedding;
			//std::cout << walker->person << " " << walker->address1 << std::endl; //debug
			std::cout << "ADDED WEDDING DATE: " << walker->wedding << " " << "UID:ID" << id << std::endl;
		}
		walker = walker->next_;
	}
}

void List::adddeath(unsigned int id, std::string death){
	Node* walker = head_;
	while(walker){
		if(walker->id == id)
		{
			walker->death = death;
			//std::cout << walker->person << " " << walker->address1 << std::endl; //debug
			std::cout << "ADDED DEATH DATE :( " << walker->death << " " << "UID:ID" << id << std::endl;
		}
		walker = walker->next_;
	}
}

void List::print(void){
	//print every node in list
	Node* walker = head_;
	//texas walker ranger node
	if (walker == NULL){
		std::cout << "This list is empty." << std::endl;
	}			
	else{
		while(walker){ //while the walker node isn't null
			std::cout << walker->firstname <<", " << walker->person << " ID:" << std::setw(3) << walker->id << std::endl;
			walker = walker->next_;
		}
	}
	std::cout << std::endl;
}

void List::printinfo(std::string id){ //will print the info of specific person
	std::stringstream ss;
	ss.str(id);
	ss.ignore(256,'D');
	unsigned int tempid;
	ss >> tempid;
	using std::cout;
	Node* walker = head_;
	while(walker){
		if(walker->id == tempid){
			cout << std::endl;
			cout << "UID: " << walker->id << std::endl;
			cout << "NAME: " << walker->firstname << " " << walker->person << std::endl;
			cout << "ADDRESS1: " << walker->address1 << std::endl;
			cout << "CITY: " << walker->city << std::endl;
			cout << "STATE: " << walker->state << std::endl;
			cout << "ZIP: " << walker->zip << std::endl;
			cout << "DATE_BIRTH: " << walker->birth << std::endl;
			cout << "DATE_DEATH: " << walker->death << std::endl;
			cout << "DATE_WEDDING: " << walker->wedding << std::endl;
			if(walker->spouse){
				cout << "SPOUSE: " << walker->spouse->firstname << " " << walker->spouse->person << std::endl;
			}
			else //for the sake of not dereferencing any null pointers
				cout << "SPOUSE: " << std::endl;
			if(walker->child.size() > 0){
				cout << "CHILD1: " << walker->child[0]->firstname << " " << walker->child[0]->person << std::endl;
			}
			else
				cout << "CHILD1: " << std::endl;
			cout << std::endl;
			return;
		}
		walker = walker->next_;
	}
}

void List::setsize(void){
	Node* walker = head_;
	size = 0;
	//texas walker ranger node
	if (walker == NULL){
		
	}			
	else{
		while(walker){ //while the walker node isn't null
			size++;
			walker = walker->next_;
		}
	}
}

int List::getsize(void){
	return size;
}

void List::removename(std::string firstname, std::string lastname){/////this is not done finish this function
	Node* walker = head_;
	if (walker->person == lastname && walker->firstname == firstname){
		head_ = walker->next_; //change head if removing head node
		delete walker; //deallocate mem for old node
		std::cout << "Removal successful:" << firstname << std::endl;
		return;
	}
	walker = head_;
	Node* walker2 = head_->next_;

	while (walker->next_){
		if (walker->next_->person == lastname && walker->next_->firstname == firstname){
			Node* temp = NULL;
			temp = walker->next_->next_;
			delete walker->next_;
			std::cout << "Removal successful:" << firstname << " " << lastname << std::endl;
			walker->next_ = temp;
			return;
		}
		walker = walker->next_;
		walker2 = walker->next_;
	}
	std::cout << "ERROR: Not found for Removal: " << firstname << " " << lastname << std::endl;
}

unsigned int List::searchname(std::string lastname, std::string firstname){
	Node* walker = head_;
	while (walker){
		if (walker->person == lastname && walker->firstname == firstname){
			return walker->id;
		}
		walker = walker->next_;
	}
	return 0;
}

Node * List::nodesearch(unsigned int new_id){
	Node* walker = head_;
	while (walker){
		if (walker->id == new_id){
			return walker;
		}
		walker = walker->next_;
	}
	return NULL;
}

List::~List(void){
	Node* del = head_;
	while(del != NULL){ //while the delete ptr isn't null
		head_ = head_->next_; //move the head down the list
		delete del; // delete current del prt
		del = head_; // move del ptr to current head ptr

	}
	head_ = NULL; //reset the head to null;
}
/////////////////////////////////
////function definitions/////////
void menu(void){//menu
	std::cout << std::endl;
	std::cout << "Choose from the menu below" << std::endl << std::endl;
	std::cout << "add name <name>  ==>  Add a new name (First Last) to the Address Book" << std::endl;
	std::cout << "add spouse <uid> <name>  ==> Add spouse of <uid> (First Last) to the Address Book" << std::endl;
	std::cout << "add child  <uid> <name>  ==>  Add a child of <uid> (First Last) to the Address Book" << std::endl;
	std::cout << "add address1 <uid> <address>  ==> Add/change the address for <uid>" << std::endl;
	std::cout << "add city <uid> <city>    ==> Add/change the city for <uid>" << std::endl;
	std::cout << "add state <uid> <state>  ==> Add/change the state for <uid>" << std::endl;
	std::cout << "add zip <uid> <zipcode>  ==> Add/change the zipcode for <uid>" << std::endl;
	std::cout << "add date_birth <uid> <ddmmyyyy>  ==> Add/change the birthday for <uid>" << std::endl;
	std::cout << "add date_wedding <uid> <ddmmyyyy>   ==> Add/change the wedding day for <uid>" << std::endl;
	std::cout << "add date_death <uid> <ddmmyyyy>   ==> Add/change the date of death for <uid>" << std::endl;
	std::cout << "remove <name> ==> this will delete a person from the address book" << std::endl;
	std::cout << "search <name>  ==> searches for name (First Last) and returns the <uid>, if found" << std::endl;
	std::cout << "print all ==>  Prints a list of ALL of the names in the Address Book with their <uid>" << std::endl;
	std::cout << "print <uid>  ==>  Prints all of the fields for <uid>" << std::endl;
	std::cout << "file  ==>  user is prompted for a filename" << std::endl;
	std::cout << "quit  ==>  processing complete" << std::endl;
 
  std::cout << "Use ftree <uid> to print tree starting from uid provided" << std::endl;
  std::cout << "----------------------------------------------------------------------" << std::endl;
  std::cout << "| This program assumes happy families. If you add a spouse after a chi|" << std::endl;
  std::cout << "|ld has been added I assume that spouse is like a step parent with no |" << std::endl;
  std::cout << "|blood relation to the previously added children. Other wise add a spo|" << std::endl;
  std::cout << "|use before conceiving a child! :) Thank you for grading!             |" << std::endl;
  std::cout << "-----------------------------------------------------------------------" << std::endl;             
	//std::cout << "cmd>";
}

int checkname(std::string name){

	for (int i = 0; i < name.length(); ++i){
		if (isalpha(name[i])){
			//do nothing
		}
		else 
		{
			return 0;
			//return false
		}
	}
	return 1;
	//string only had letters return 1;
}

void fileread(class List& book){
  std::cin.clear();
	std::ifstream ifile; //file
	std::string filename; //file name to be opened
	std::cout << "Enter file name or file path: ";
	std::cin >> filename;
	ifile.open(filename.c_str()); //opening file

	if(! ifile.is_open()){ //if file no open exit function
		std::cout << "The file was not opened. Did you type the right name?" << std::endl;
		return;
	}
	std::string file_line, cmd, cmd2, lastname, firstname; //line of file, cmd to be used, and name
	std::string name;// please delete this, this is just so it'll compile right now
	while (/*getline(ifile, file_line)*/ifile.good() ){
//		cmd = file_line.substr(0,file_line.find(',')); // slice first cmd from line of file
//		name = file_line.substr(file_line.find(',')+1);
		std::string trash; // to grab empty comma fields
		getline(ifile,cmd, ',');
		cmd.erase(std::remove(cmd.begin(), cmd.end(), ' '), cmd.end()); // because you have a random space in one of your lines!!!!!!!!! >.<
		//getline(ifile,cmd2, ',');
		/*getline(ifile,firstname,',');//this is going to have to be moved into each corresponding if
		getline(ifile,lastname, '\n');
		lastname.erase(std::remove(lastname.begin(), lastname.end(), '\r'), lastname.end()); //because the provided csv file is written in windows there are trailing \r s in the file this deletes them
		//firstname.erase(std::remove(firstname.begin(), lastname.end(), '\r'), firstname.end());//^^^^^^^^
		//std::cout << cmd << "  " << name << std::endl; //debug*/
		if (cmd == "add"){
			getline(ifile,cmd2, ',');
			if(cmd2 == "name"){
				getline(ifile,firstname,' ');//why the heck aren't the first and last names separated by a comma?!?!?!?! >.<
				getline(ifile,lastname, ',');
				lastname.erase(std::remove(lastname.begin(), lastname.end(), '\r'), lastname.end()); //because the provided csv file is written in windows there are trailing \r s in the file this deletes them
				getline(ifile,trash);
				for (int i = 0; i < lastname.length(); ++i){
					lastname[i] = tolower(lastname[i]);
				}//convert string to lowercase
				for (int i = 0; i < firstname.length(); ++i){
					firstname[i] = tolower(firstname[i]);
				}//convert string to lowercase
				book.addname(lastname, firstname);
				//book.setsize();
				//std::cout << book.getsize() << std::endl;
			}
			else if(cmd2 == "spouse"){
				std::string id; // id of person that spouse is being added to with ID in it
				unsigned int numid;// id of person without ID
				getline(ifile,id, ',');
				std::stringstream ss;
				ss.str(id); //turn the id "Id###" into a stream to be parse for the ### part of the string
				ss.ignore(256,'D');
				ss >> numid;
				getline(ifile,firstname,' ');//this is going to have to be moved into each corresponding if
				getline(ifile,lastname);
				lastname.erase(std::remove(lastname.begin(), lastname.end(), '\r'), lastname.end()); //because the provided csv file is written in windows there are trailing \r s in the file
				for (int i = 0; i < lastname.length(); ++i){
					lastname[i] = tolower(lastname[i]);
				}//convert string to lowercase
				for (int i = 0; i < firstname.length(); ++i){
					firstname[i] = tolower(firstname[i]);
				}//convert string to lowercase
				book.addspouse(numid, lastname, firstname);

			}
			else if(cmd2 == "child"){
				std::string id; // id of person that spouse is being added to with ID in it
				unsigned int numid;// id of person without ID
				getline(ifile,id, ',');
				std::stringstream ss;
				ss.str(id); //turn the id "Id###" into a stream to be parse for the ### part of the string
				ss.ignore(256,'D');
				ss >> numid;
				getline(ifile,firstname,' ');//this is going to have to be moved into each corresponding if
				getline(ifile,lastname);
				lastname.erase(std::remove(lastname.begin(), lastname.end(), '\r'), lastname.end()); //because the provided csv file is written in windows there are trailing \r s in the file
				for (int i = 0; i < lastname.length(); ++i){
					lastname[i] = tolower(lastname[i]);
				}//convert string to lowercase
				for (int i = 0; i < firstname.length(); ++i){
					firstname[i] = tolower(firstname[i]);
				}//convert string to lowercase
				book.addchild(numid, lastname, firstname);
			}
			else if(cmd2 == "address1"){
				std::string address, id;
				unsigned int numid;
				getline(ifile,id, ',');
				std::stringstream ss;
				ss.str(id); // make the string stream be the string id consisting of the id with ID like so "ID###"
				ss.ignore(256,'D');
				ss >> numid;// parses the string stream for the actual # in read in id of format "ID###"
				//std::cout << numid << std::endl; // debug
				getline(ifile, address);
				address.erase(std::remove(address.begin(), address.end(), '\r'), address.end());
				book.addaddress(numid, address);
			}
			else if (cmd2 == "city"){
				std::string city, id;
				unsigned int numid;
				getline(ifile,id, ',');
				std::stringstream ss;
				ss.str(id);
				ss.ignore(256, 'D');
				ss >> numid;
				getline(ifile, city);
				city.erase(std::remove(city.begin(), city.end(), '\r'), city.end()); // anytime you see this it's because I'm erasing a /r left by your version of the example csv file that breaks output
				book.addcity(numid, city);
				
			}
			else if (cmd2 == "state"){
				std::string state, id;
				unsigned int numid;
				getline(ifile,id, ',');
				std::stringstream ss;
				ss.str(id);
				ss.ignore(256, 'D');
				ss >> numid;
				getline(ifile, state);
				state.erase(std::remove(state.begin(), state.end(), '\r'), state.end());
				book.addstate(numid, state);
			}
			else if (cmd2 == "zip"){
				std::string zip, id;
				unsigned int numid, numzip;
				getline(ifile,id, ',');
				std::stringstream ss, ss2;
				ss.str(id);
				ss.ignore(256, 'D');
				ss >> numid;
				getline(ifile, zip);
				zip.erase(std::remove(zip.begin(), zip.end(), '\r'), zip.end());
				ss2.str(zip); //turn the zip into a stream to be converted to int
				ss2 >> numzip;
				book.addzip(numid, numzip);
			}
			else if(cmd2 == "date_birth"){
				std::string birth, id;
				unsigned int numid;
				getline(ifile,id, ',');
				std::stringstream ss;
				ss.str(id); // make the string steam be the string id consisting of the id with ID like so "ID###"
				ss.ignore(256,'D');
				ss >> numid;// parses the string stream for the actual # in read in id of format "ID###"
				//std::cout << numid << std::endl; // debug
				getline(ifile, birth);
				birth.erase(std::remove(birth.begin(), birth.end(), '\r'), birth.end());
				book.addbirth(numid, birth);
			}
			else if(cmd2 == "date_wedding"){
				std::string wedding, id;
				unsigned int numid;
				getline(ifile,id, ',');
				std::stringstream ss;
				ss.str(id); // make the string steam be the string id consisting of the id with ID like so "ID###"
				ss.ignore(256,'D');
				ss >> numid;// parses the string stream for the actual # in read in id of format "ID###"
				//std::cout << numid << std::endl; // debug
				getline(ifile, wedding);
				wedding.erase(std::remove(wedding.begin(), wedding.end(), '\r'), wedding.end());
				book.addwedding(numid, wedding);
			}
			else if(cmd2 == "date_death"){
				std::string death, id;
				unsigned int numid;
				getline(ifile,id, ',');
				std::stringstream ss;
				ss.str(id); // make the string steam be the string id consisting of the id with ID like so "ID###"
				ss.ignore(256,'D');
				ss >> numid;// parses the string stream for the actual # in read in id of format "ID###"
				//std::cout << numid << std::endl; // debug
				getline(ifile, death);
				death.erase(std::remove(death.begin(), death.end(), '\r'), death.end());
				book.adddeath(numid, death);
			}
		}

		else if (cmd == "search"){
			getline(ifile,firstname,' ');//this is going to have to be moved into each corresponding if
			getline(ifile,lastname, ',');
			lastname.erase(std::remove(lastname.begin(), lastname.end(), '\r'), lastname.end()); //because the provided csv file is written in windows there are trailing \r s in the file this deletes them
			getline(ifile,trash, ','); //trash csv field
			getline(ifile,trash); //trash csv field
			for (int i = 0; i < lastname.length(); ++i){
				lastname[i] = tolower(lastname[i]);
			}//convert string to lowercase
			for (int i = 0; i < firstname.length(); ++i){
				firstname[i] = tolower(firstname[i]);
			}//convert string to lowercase
			unsigned int tempid;
			if( tempid = book.searchname(lastname, firstname) ){
				std::cout << "FOUND: " << lastname << ", " << firstname << ' ' << "ID:" << std::setw(3) << tempid <<std::endl;
			}
			else{
				std::cout << "NOT FOUND: " << lastname << ", " << firstname << std::endl;
			}
		}

		else if (cmd == "remove"){//still need to change this
			getline(ifile,firstname, ' ');
			getline(ifile,lastname);
			for (int i = 0; i < firstname.length(); ++i){
				firstname[i] = tolower(name[i]);
			}//convert string to lowercase
			for (int i = 0; i < lastname.length(); ++i){
				lastname[i] = tolower(lastname[i]);
			}//convert string to lowercase
			book.removename(name,name);
			//book.setsize();//think this function might actually be useless remove if we never end up using this
			//std::cout << book.getsize() << std::endl;

		}

		else if (cmd == "print"){
			std::string cmd2;
			getline(ifile,cmd2,',');
			if(cmd2 == "all"){
				getline(ifile,trash, ','); //trash csv field
				getline(ifile,trash); //trash csv field
				book.print();
		
			}
			else{
				getline(ifile,trash, ','); //trash csv field
				getline(ifile,trash); //trash csv field
				book.printinfo(cmd2);
			}
		}

		else if (cmd == "quit"){
			ifile.close();
			exit(1);
			//end program;
		}
		/////////////////////////////////////////////////reuse code from main//////////
	}
	ifile.close();
}



