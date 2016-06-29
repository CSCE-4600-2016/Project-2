// Asad Waheed
// Insertion Sort in Java
// Compile: javac InsertionSort.java
// Run:		java InsertionSort

/* insertion sort function */
public class InsertionSort
{
	void insertionSort(int[] arr) // Passing it an array to sort
	{
		int
			i,j,		// counter variables
			newValue;	// swapper variable

		for( i = 1; i < arr.length; i++ )
		{
			newValue = arr[i];	//	Sets newValue to current index's value
			j = i;


			while( j > 0 && arr[j - 1] > newValue)
    		{
				arr[j] = arr[j - 1];	// Swap current and previous to current
    			j--;
			}

			arr[j] = newValue;
		}

	}

	static void printArray(int arr[])
	{
		int i;
		for( i = 0; i < arr.length; i++)
		{
			System.out.print(arr[i] + " ");
		}
	}
	public static void main(String[]args)
	{
		// Sanity check, also a pretty good album. Check it out.
		System.out.println("Shiver in eternal darkness\n");
		
		// Test array; for bigger numbers use long long
		int testArray[] = {24, 71, 98, 10, 53};

		// Display unsorted array
		System.out.print("\nOriginal array:\t");
		InsertionSort.printArray(testArray);
		System.out.println();
		System.out.println();

		// Passing test data to the insertionSort function
		InsertionSort it = new InsertionSort();
		it.insertionSort(testArray);
		
		// Display sorted array
		System.out.println("Sorted array:\t");
		InsertionSort.printArray(testArray);
		System.out.println("\n\n\n");

	}
}
