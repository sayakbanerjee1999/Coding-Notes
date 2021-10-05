class Solution {
    public int findCircleNum(int[][] M) {
      int ans  = BFS(0, M);
        return ans;
    }
    
     public static void BFSHelper(int adj_mat[][],int sv, boolean visited[]) {
	  Queue<Integer> q = new LinkedList<>();
	  q.add(sv);
	  visited[sv] = true;
	  int v = adj_mat.length;
	  while(!q.isEmpty()) {
		  int front = q.poll();
		  for(int i =0; i <v; i++) {
        //check for adjacent and unvisited nature
			  if(adj_mat[front][i] == 1 && visited[i] == false) {
				  q.add(i);
				  visited[i] = true;
			  }
		  }
	  }
   }	
	
   public static int BFS(int ans, int adj_mat[][]) {
	   int v = adj_mat.length;
     //for keeping the visited nodes
	   boolean visited[] = new boolean[v];
	   for(int i =0; i<v; i++) {
		   if(visited[i] == false){
         //if one component found
			   ans++;
               BFSHelper(adj_mat, i, visited);
           }
	   }

       return ans;
   }
}
