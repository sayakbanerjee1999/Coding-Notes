class Solution{
    // Returns true if graph has path more than k length
    static Boolean pathMoreThanKK(int V, int src, int k, Map<Integer,List<int[]>> m)
    {
       
      // Create a path array with nothing included
      // in path
      boolean path[] = new boolean[V];
 
      Arrays.fill(path, false);
 
      // Add source vertex to path
      path[src] = true;
 
      return pathMoreThanKUtil(src, k, path, m);
    }
 
    // Prints shortest paths from src to all other vertices
    static Boolean pathMoreThanKUtil(int src, int k, boolean[] path, Map<Integer,List<int[]>> map)
    { 
       
      // If k is 0 or negative, return true;
      if (k <= 0)
        return true;
 
      // Get all adjacent vertices of source vertex src and
      // recursively explore all paths from src.
      if (map.containsKey(src)){
          for (int[] next:map.get(src)){
          int index = 0;
          
          // Get adjacent vertex and weight of edge
          int v = next[0];
          int w = next[1];
          
          // increase theindex
          index++;
 
        // If vertex v is already there in path, then
        // there is a cycle (we ignore this edge)
          if (path[v] == true)
            continue;
 
        // If weight of is more than k, return true
          if (w >= k)
            return true;
 
        // Else add this vertex to path
          path[v] = true;
 
        // If this adjacent can provide a path longer
        // than k, return true.
        if (pathMoreThanKUtil(v, k-w, path,map))
          return true;
 
        // Backtrack
        path[v] = false;
      }
      }
      
 
      // If no adjacent could produce longer path, return
      // false
      return false;
    }
 
  
    
    static Boolean pathMoreThanK(int V, int E, int K, int[] A){
        // Code Here
        Map<Integer,List<int[]>> map=new HashMap<>();
        int i = 0;
        while(i<=A.length-3){
            map.putIfAbsent(A[i],new ArrayList<>());
            map.get(A[i]).add(new int[]{A[i+1],A[i+2]});
            i+=3;
        }
       
        boolean res = pathMoreThanKK(V,0,K,map);
        return res;
    }
    
}
