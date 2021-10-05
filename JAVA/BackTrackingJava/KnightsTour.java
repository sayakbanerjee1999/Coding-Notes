class Main{
public static void printKnightsTour(int[][] chess, int r, int c, int move){
  //check for the base condition
  if (r<0 || c<0 || r>=chess.length || c>=chess.length || chess[r][c]>0){
    return;
  } else if (move==chess.length*chess.length){
    //if covered all the blocks of the board
    //add move value to the block
    //display the board
    chess[r][c] = move;
    display(chess);
    //backtrack make it as unvisited and return
    chess[r][c] = 0;
    return;
  }
  //else mark the bloack with move
  chess[r][c] = move;
  //explore all the 8 directions
  printKnightsTour(chess,r-2,c+1,move+1);
  printKnightsTour(chess,r-1,c+2,move+1);
  printKnightsTour(chess,r+1,c+2,move+1);
  printKnightsTour(chess,r+2,c+1,move+1);
  printKnightsTour(chess,r+2,c-1,move+1);
  printKnightsTour(chess,r+1,c-2,move+1);
  printKnightsTour(chess,r-1,c-2,move+1);
  printKnightsTour(chess,r-2,c-1,move+1);
  //again backtrack
  chess[r][c] = 0;
}

public static void display(int[][] chess){
for (int i=0;i<chess.length;i++){
  for (int j=0;j<chess[0].length;j++) {
      System.out.print(chess[i][j]+" ");
    }
  System.out.println();
  }
}

}
