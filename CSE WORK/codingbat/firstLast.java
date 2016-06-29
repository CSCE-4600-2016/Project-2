public class firstLast {
  public boolean firstLast6(int[] nums)
  {
    if((nums[0] == 6) || (nums[nums.length-1] == 6))
      return true;
    else
      return false;
  }
  public static void main(String[]args)
  {
    int test[] = {2,7,10,6,3,1,4,0,8};
    firstLast testObj = new firstLast();
    testObj.firstLast6(test);
  } 
}
