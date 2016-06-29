/*
	Asad Waheed
	File: main.cpp
	Desc: Program Entry Point/Driver File
	Compile: make
	Run:	 make run
	Clean:	 make clear
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iterator>



using namespace std;

/* DOES NOT WORK ASDF IT WORKED LAST SEMESTER
 * Source: http://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c
class CSVIterator
{   
    public:
        typedef std::input_iterator_tag     iterator_category;
        typedef CSVRow                      value_type;
        typedef std::size_t                 difference_type;
        typedef CSVRow*                     pointer;
        typedef CSVRow&                     reference;

        CSVIterator(std::istream& str)  :m_str(str.good()?&str:NULL) { ++(*this); }
        CSVIterator()                   :m_str(NULL) {}

        // Pre Increment
        CSVIterator& operator++()               {if (m_str) { (*m_str) >> m_row;m_str = m_str->good()?m_str:NULL;}return *this;}
        // Post increment
        CSVIterator operator++(int)             {CSVIterator    tmp(*this);++(*this);return tmp;}
        CSVRow const& operator*()   const       {return m_row;}
        CSVRow const* operator->()  const       {return &m_row;}

        bool operator==(CSVIterator const& rhs) {return ((this == &rhs) || ((this->m_str == NULL) && (rhs.m_str == NULL)));}
        bool operator!=(CSVIterator const& rhs) {return !((*this) == rhs);}
    private:
        std::istream*       m_str;
        CSVRow              m_row;
}; */

/* Just reads the whole dang file, not chopping out '|' )*/
void LoadData(ifstream &in, char ch)
{
	string name;
	string delimiter = "|";	 // ok, this is what I need to get rid of
	
	 while (!in.eof())       // When the file buffer reaches end-of-file, wh$
        {
               in.get(ch);  
										// gets chars one at a time
                cout << ch;             // output one char at a time
        }
        in.close();                     // Close file; we are done now
        cout << endl; 
}
/** 
 * So below are my three algorthimic sorts, Merge, Quick, and Quick+Insert
 * They are not going to be used on the data until I figure out how to parse the 
 * pop density column out of the file, iteratively feed those ints into an array, then
 * pass that array plus any other necessary params to these algorithms. 
 
 * Please keep in mind that I understand how these algorithms work conceptually and am even able to
 * wholly follow the theoretical aspects in class, but parsing files
 * is a weakness that hasn't been remedied by the help lab, many c/c++ texts,
 * stackOVerflow, MSDN, Cprogramming, CPlusPlus, Reddit, or google in general. 
 
 * I happened to stumble across a great piece of code called CSVIterator last semester that really
 * helped with Dr. Burke's insane file parsing requirements, but that was only once instance, and I 
 * do not know to this day how I managed to get that CSVIterator class to work. Whatever I did back then is not successfully
 * replicated in this program here. If anyone can offer me a solid resource on file parsing with 
 * non-standard delimiters feel free to do so. Thanks. */

/** 
 * MergeSort. Following my class notes pseudo-code.
 * A = array containing sequence
 * p = start index
 * r = end-index
 * */

/* merge routine */
void merge(int A[], int p, int q, int r)
{
	unsigned const int infinity = 999;
	int n1 = q - p + 1;
	int n2 = r - q;
	
	int L[n1 + 1];
	int R[n2 + 1];
	int i, j;
	for(i = 1; i <= n1; i++)
	{
		L[i] = A[p + i - 1];
	}
	for(j = 1; j <= n2; j++)
	{
		R[j] = A[q+j];
	}
	
	L[n1 + 1] = infinity;
	R[n2 + 1] = infinity;
	i, j = 1;	
} 

void MergeSort(int A[], int p, int r)
{
	
	if(p < r)	// as long as sequence bigger than 1
	{
		//midpoint
		int q = (p+r)/2;
		MergeSort(A,p,q);	/*	First half	*/
		MergeSort(A,q+1,r); /*	Second half	*/
		merge(A,p,q,r);
	}
		
}

/**
 * 	QuickSort function with the median-of-three partitioning strategy.
 *  Reference: CSCE3110 Textbook, class notes
 * */
int MedianThree(int A[], int left, int right)
{
	int center = (left + right) / 2;
	
	if(A[center] < A[left])
	{
		std::swap(A[ left ], A[ center ]);
	}
	if(A[right] < A[left])
	{
		std::swap(A[ left ], A[ right ]);
	}
	if(A[right] < A[center])
	{
		std::swap(A[ center ], A[ right ]);
	}
	
	// Place pivot at position right - 1
	
	std::swap(A[ center ] , A[ right - 1 ]);
	return A[ right - 1]; 
}

void QuickSort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = MedianThree(A,p,r);
		QuickSort(A,p,q-1);
		QuickSort(A,q,r);
	}
}
/**
 *  Last but not least the Hybrid QuickSort + InsertionSort algorithm. Referencing the class
 *  text for this.
 * */
 void HybridQuickSort(int A[], int left, int right)
 {
	 if(left + 10 <= right)
	 {
		 const int pivot = MedianThree(A,left,right);
		 
		 //begin partitioning
		 int i = left, j = right - 1;
		 
		 for(;;)
		 {
			 while(A[ ++i ] < pivot ){}
			 while(pivot < A[ --j ]){}
			 // This is as far as I got.
		 }
	 }
 }
int main()
{
	ifstream in("pop_density.txt");
	
	char c = ' ';	// gcc's warnings on empty literals. Amazing.
	
	LoadData(in, c);	// Loads the data and nothing more
	
	std::ifstream       file("plop.csv");

    /* Simplest possible implementation of the CSVIterator class and this also fails. 
    
    for(CSVIterator loop(file);loop != CSVIterator();++loop)
    {
        std::cout << "4th Element(" << (*loop)[3] << ")\n";
    }
    **/


	return 0;
}
