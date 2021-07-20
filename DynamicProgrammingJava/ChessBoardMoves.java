import java.util.*;
import java.io.*;
public class Main
{
    public static long getMoves(int row, int col, int val, int[][] board){
        long moves = 0;
        if (val==1 || val==3){
            //l,r,u,d
            //up
            for (int i=row-1;i>=0;--i){
                if (board[i][col]!=0)
                    break;
                ++moves;
            }
            //down
            for (int i=row+1;i<board.length;++i){
                if (board[i][col]!=0)
                    break;
                ++moves;
            }
            //left
            for (int i=col-1;i>=0;--i){
                if (board[row][i]!=0)
                    break;
                ++moves;
            }
            //right
            for (int i=col+1;i<board[0].length;++i){
                if (board[row][i]!=0)
                    break;
                ++moves;
            }
        }
        if (val==2 || val==3){
            //diag bot right
            for (int i=1; row+i<board.length && col+i<board[0].length; ++i){
                if (board[row+i][col+i]!=0)
                    break;
                ++moves;
                
            }
            //diag bot left
            for (int i=1; row+i<board.length && col-i>=0; ++i){
                if (board[row+i][col-i]!=0)
                    break;
                ++moves;
                
            }
            //diag top right
            for (int i=1; row-i>=0 && col+i<board[0].length; ++i){
                if (board[row-i][col+i]!=0)
                    break;
                ++moves;
                
            }
            //diag top left
            for (int i=1; row-i>=0 && col-i>=0; ++i){
                if (board[row-i][col-i]!=0)
                    break;
                ++moves;
                
            }
        }
        return moves;
        
    }
    
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int c = sc.nextInt();
        int[][] board = new int[r][c];
        //1 for R
        //2 for B
        //3 for Q
        //0 for empty
        for (int i=0;i<r;i++){
            for (int j=0;j<c;j++){
                board[i][j] = sc.nextInt();
            }
        }
        long moves = 0;
        for (int i=0;i<r;i++){
            for (int j=0;j<c;j++){
                if (board[i][j] == 0)
                    continue;
                moves += getMoves(i,j,board[i][j],board);
            }
        }
        System.out.println(moves);
	}
}
