// Asad Waheed
// Vectors Practice


#include <iostream>
#include <vector>
using namespace std; 

int main()
{
	// Initializing w/ primitive data type
	std::vector<int>my_vec;

	// Adding values
	my_vec.push_back(500);
	my_vec.push_back(501);
    my_vec.push_back(502);
	my_vec.push_back(503);
	my_vec.push_back(504);

	// Getting size of vector
	cout << "vector size is " << my_vec.size() << endl;

	// Iterating and accessing members of the vector
	for (int i = 0; i < my_vec.size(); i++)
	{
		// Printing index numbers and values
		cout << "Index [" << i << "]\tValue: " << my_vec.at(i) << endl;
	}

	// Erase elements
	my_vec.erase(my_vec.begin());		// my_vec.begin() means the iterator will start at the 0th index
	return 0;
}
