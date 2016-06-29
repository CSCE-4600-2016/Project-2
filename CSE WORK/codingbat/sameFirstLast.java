/*
Given an array of ints, return true if the array is length 1 or more, 
and the first element and the last element are equal.
*/

public class sameFirstLast
{
	public boolean sameFirstLast(int[]nums)
	{
		 if((nums.length >= 1) && (nums[0]==(nums[nums.length-1])))
  		 	return true;
  		 else
  			return false;
	}

	public static void main(String[]args)
	{
		int test[] = {2 ,4 ,7, 3}; // returns false
		sameFirstLast testObj = new sameFirstLast();
		testObj.sameFirstLast(test);

	}

}
