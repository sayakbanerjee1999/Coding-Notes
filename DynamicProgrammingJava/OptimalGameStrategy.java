/*1. You are given an array(arr) of length N, where N is an even number.
2. The elements of the array represent N coins of values arr1,arr1...arrN.
3. You are playing a game against an opponent in an alternative way, where the opponent is equally smart.
4. In this game, a player selects either the first or the last coin from the row in every turn, removes it from the row permanently, and receives the value of the coin.
5. You have to find the maximum possible amount of money you can win if you make the first move.
*/


class Solution {
    public int PredictTheWinner(int[] nums) {
        int[][] dp = new int[nums.length][nums.length];
        
        for (int g=0;g<dp.length;g++){
            for (int i=0,j=g;j<dp.length;i++,j++){
                if (g==0){
                    dp[i][j] = arr[i];
                } else if (g==1){
                    dp[i][j] = Math.max(arr[i],arr[j]);
                } else{
                  //you play smart in your turn and wait for worst in the opponent's turn
                  //hence minimum of what opponent can choose
                  //finally max of them together with your own move
                    int val1 = arr[i] + Math.min(dp[i+2][j], dp[i+1][j-1]);
                    int val2 = arr[j] + Math.min(dp[i+1][j-1], dp[i][j-2]);
                    int val = Math.max(val1, val2);
                    dp[i][j] = val;
                }
            }
        }
        return dp[0][nums.length-1];
    }
}
