/////////////////////////////////////////////////////////////

					README

/////////////////////////////////////////////////////////////

In this program I plan to divide out the 3 types of sort by class as follows:


			  |--------------> MergeSort
			  |
			  |
	Sort----------------------> QuickSort---> QuickSort + InsertionSort Hybrid


So the class Sort will be a base class for the other sorts. The hybrid sort
I plan to make a derived class of QuickSort since all that is really happening
is another if-block/switch case with InsertionSort inside it. Why redo all 
the work for QuickSort when I'm only adding small functionality? 
