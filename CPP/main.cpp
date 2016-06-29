// C++ Files and Streams Tutorial 

#include <iostream>
#include <string>
#include <fstream>
#include "functions.h"

using namespace std; 

char PersonName[25];
char Occupation[25];
char Location[25];
char References[25];

int main(int argc, char *argv[])
{
	char choice[10];
	cout << "\n\tPersonnel DB 1.0\t\n\n" << endl;
	
	// Menu
	
		cout << "\n|-----------------Main Menu---------------------|";
		cout << "\n|	Create a Person - C			|";
		cout << "\n|	Edit Person Info - E			|";
		cout << "\n|	Display a Person - D			|";
		cout << "\n|	Save a Person - S			|";
		cout << "\n|	Load a Person - L			|";
		cout << "\n|	Quit - Q	       			|";
		cout << "\n|		       				|";
		cout << "\n|-----------------------------------------------|\n";
		cout << "\n\nPlease open this program in full screen for best results\n\n";
	
	
	while(choice[0] != 'q')
	{
		
		cout << ">	";
		cin >> choice;

		cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
		

		switch(choice[0])
		{
			case 'c': CreatePerson();
				break;
			case'e': EditPerson();
				break;
			case'd': DisplayPerson();
				break;
			case's': SavePerson();
				break;
			case'l': LoadPerson();
				break;
			case 'q': cout << "Bye.\n\n";
				break;	
			default: cout << "\nINVALID INPUT TRY AGAIN\n";				
		}
	
	}
	return 0;
}

void CreatePerson()
{

}
//-----------------------------------
void EditPerson()
{
}
//-----------------------------------
void DisplayPerson()
{
	cout << "\nPerson Data";
	cout << "\n---------------";
	cout << "\nName: " << PersonName;
	cout << "\nOccupation: " << Occupation;
	cout << "\nLocation: " << Location;
	cout << "\nReferences: " << References;
	cout << "\n--------------------------------\n\n";
}
//-----------------------------------
void SavePerson()
{
	try
	{
		ofstream dataFile;
		dataFile.open("data.txt", ios::out);	//default ios flag is called out. out writes data file
		
		dataFile << "Name: Charles Germany" << "\n"; 
		dataFile << "Occupation: Louis CK Faggot" << "\n"; 
		dataFile << "Location: BastardDildoTown" << "\n";
		dataFile << "References: Pidgey" << "\n"; 
		dataFile.close();
		
		cout << "Success! Data saved to file\n";
	}
	catch(exception X)
	{
		cout <<"\nERROR: Could not save Person"<< endl;	
	}
}
//-----------------------------------
void LoadPerson()
{
	try
	{
		ifstream dataFile;
		dataFile.open("data.txt", ios::in);
		
		dataFile >> PersonName;
		dataFile >> Occupation;
		dataFile >> Location;
		dataFile >> References;
		
		dataFile.close();
		
		cout << "Sucess, data was written to file!\n\n";
	}
	catch(exception X)
	{
		cout << "ERROR: Could not save person data. Please try again.\n\n";
	}
}
//-----------------------------------

