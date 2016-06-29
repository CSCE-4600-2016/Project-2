#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
  vector<int> myVector;	//{}
  vector<int> myVector2(5,0); //{0,0,0,0,0}
  cout << "line 12 exec" << endl;
  myVector2.push_back(10); //{0,0,0,0,0,10}
  myVector2.pop_back();	//{0,0,0,0,0}

  for( int i = 0; i < myVector2.size(); i++)
  {
	// assign a val to a pos. in vector
	myVector2[i] = i;
	//{0,1,2,3,4}
  }
	cout << "third element: " << myVector2[3] << endl;
	cout << "line 23 exec" << endl;
 
	cout << "Last element: " << myVector.back() << endl;
	cout << "line 26 exec" << endl;

	cout << "First element: " << myVector2.front() << endl;
	cout << "line 28 exec" << endl;

	myVector2.erase(myVector2.begin() + 3); //{0,1,3,4}

	cout << "-----\n\n";


	vector<int> newVector;

	return 0;
}
