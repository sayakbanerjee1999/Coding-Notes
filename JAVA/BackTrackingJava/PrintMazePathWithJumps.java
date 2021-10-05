public class Main{
public static void printPaths(int sr, int sc, int dr, int dc, String temp){
  if(sr==dr && sc==dc){
    System.out.println(temp);
    return;
  } 
  //for horizontal
  for (int i=1;i<dc-sc;i++){
    printPaths(sr,sc+i,dr,dc,temp+"h"+i);
  }
  //for vertical
  for (int i=1;i<dr-sr;i++){
    printPaths(sr+i,sc,dr,dc,temp+"v"+i);
  }
  //for diagonal have to check both conditions
  for (int i=1;i<dc-sc && i<dr-sr;i++){
    printPaths(sr+i,sc+i,dr,dc,temp+"d"+i);
  }
}
}
