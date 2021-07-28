/*
You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes a bidirectional path between garden xi to garden yi. In each garden, you want to plant one of 4 types of flowers.

All gardens have at most 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)th garden. The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer exists.

 

Example 1:

Input: n = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Explanation:
Gardens 1 and 2 have different types.
Gardens 2 and 3 have different types.
Gardens 3 and 1 have different types.
Hence, [1,2,3] is a valid answer. Other valid answers include [1,2,4], [1,4,2], and [3,2,1].
*/


class Solution {
    List<List<Integer>> adj;
    int[] color;
    public int[] gardenNoAdj(int n, int[][] paths) {
        int m= 4; 
        adj= new ArrayList<>();
        color= new int[n];
        for(int i=0;i<n;i++) adj.add(new ArrayList<>());
        for(int i=0;i<paths.length;i++){
            adj.get(paths[i][0]-1).add(paths[i][1]-1);
            adj.get(paths[i][1]-1).add(paths[i][0]-1);
        }
        solve(m,n,0);
        return color;
    }
    public boolean solve(int currentColor,int totalVertex,int currVertex){
        if(currVertex==totalVertex) return true;
        for(int i=1;i<=currentColor;i++){
            if(isSafe(i,currVertex)){
                color[currVertex] = i;
                if(solve(currentColor, totalVertex, currVertex+1)){
                    return true;
                }
                color[currVertex]=0;
            }
        }
        return false;
    }
    public boolean isSafe(int currentColor, int currVertex){
        for(int neighbour : adj.get(currVertex)){
            if(currentColor == color[neighbour]) return false;
        }
        return true;
    }
}
