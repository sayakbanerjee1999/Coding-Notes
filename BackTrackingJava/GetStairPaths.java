public class Main{
  public static ArrayList<String> getPaths(int n){
    if (n==0){
      //if 0 means we have end now will send empty string list to previous step to further append recursively
      ArrayList<String> blankRes = new ArrayList<String>();
      blankRes.add("");
      return blankRes;
    } else if (n<0){
      //negative means not possible so return null list
      ArrayList<String> blankRes = new ArrayList<String>();
      return blankRes;
    }
    //for step 1
    ArrayList<String> p1 = getPaths(n-1);
    //for step 2
    ArrayList<String> p2 = getPaths(n-2);
    //for step 3
    ArrayList<String> p3 = getPaths(n-3);
    //final list
    ArrayList<String> paths = new ArrayList<String>();
    //for paths in all the 3 paths append to main result with according values at top
    for (String path:p1)
      paths.add(1+path);
    for (String path:p2)
      paths.add(2+path);
    for (String path:p3)
      paths.add(3+path);
    return paths;
  }
}
