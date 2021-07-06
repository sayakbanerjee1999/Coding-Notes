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
