class Result {

    /*
     * Complete the 'journeyToMoon' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER n
     *  2. 2D_INTEGER_ARRAY astronaut
     */
     public static HashMap<Integer,Integer> findCircleNum(int[][] M) {
      HashMap<Integer,Integer> hm = BFS(0, M);
        return hm;
    }
    
     public static int BFSHelper(int adj_mat[][],int sv, boolean visited[],int z) {
      Queue<Integer> q = new LinkedList<>();
      q.add(sv);
      visited[sv] = true;
      int v = adj_mat.length;
      while(!q.isEmpty()) {
          int front = q.poll();
          for(int i =0; i <v; i++) {
              if(adj_mat[front][i] == 1 && visited[i] == false) {
                  q.add(i);
                  visited[i] = true;
                  z++;
              }
          }
      }
      return z;
   }    
    
   public static HashMap<Integer,Integer> BFS(int ans, int adj_mat[][]) {
       int v = adj_mat.length;
       HashMap<Integer,Integer> hm = new HashMap<Integer,Integer>();
       boolean visited[] = new boolean[v];
       for(int i =0; i<v; i++) {
           if(visited[i] == false){
               ans++;
               int k = BFSHelper(adj_mat, i, visited,1);
               hm.put(ans,k);
           }
       }

       return hm;
   }
   
    public static int journeyToMoon(int n, List<List<Integer>> astronaut) {
    // Write your code here
    int[][] mat = new int[n][n];
        for (List<Integer> a:astronaut){
            mat[a.get(0)][a.get(1)]=1;
            mat[a.get(1)][a.get(0)]=1;
        }
       HashMap<Integer,Integer> hm = findCircleNum(mat); 
       int res = n;
        res *= n-1;
        res /= 2;
       for(int i=1;i<=hm.size();i++){
           int x = hm.get(i);
            x *= (hm.get(i)-1);
            x /= 2;
            res = res - x;
       }
    return res;
    }

}
