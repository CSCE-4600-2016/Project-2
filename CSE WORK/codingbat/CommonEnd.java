public class CommonEnd {
  public boolean commonEnd(int[] a, int[] b)
  {
    if((a[0] == b[0]) || (a[a.length-1] == b[b.length-1]))
      return true;
    else
      return false;
  }

  public static void main(String[]args)
  {
    // Test data; both arrays meet "true" condition of commonEnd function
    int testA[] = {6,2,8};
    int testB[] = {6,0,3,8};

    CommonEnd testObj = new CommonEnd();
    testObj.commonEnd(testA,testB);
  }
}

