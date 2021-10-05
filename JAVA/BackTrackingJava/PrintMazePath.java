public class Main{
public static void printPaths(int sr, int sc, int dr, int dc, String temp){
  //base case; cant traverse anymore
  if(sr>dr || sc>dc){
    return;
  } 
  //if equal then we found an answer
  if(sr==dr && sc==dc){
    System.out.println(temp);
    return;
  } 
  //explore the 2 options
  //for horizontal
  printPaths(sr,sc+i,dr,dc,temp+"h"+i);
  //for vertical
  printPaths(sr+i,sc,dr,dc,temp+"v"+i);
}
}
