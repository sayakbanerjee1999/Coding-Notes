// Returns true if graph has path more than k length
    boolean pathMoreThanK(int src, int k)
    {
       
      // Create a path array with nothing included
      // in path
      boolean path[] = new boolean[V];
 
      Arrays.fill(path, false);
 
      // Add source vertex to path
      path[src] = true;
 
      return pathMoreThanKUtil(src, k, path);
    }
 
    // Prints shortest paths from src to all other vertices
    boolean pathMoreThanKUtil(int src, int k, boolean[] path)
    { 
       
      // If k is 0 or negative, return true;
      if (k <= 0)
        return true;
 
      // Get all adjacent vertices of source vertex src and
      // recursively explore all paths from src.
      ArrayList<AdjListNode> it = adj.get(src);
 
      int index = 0;
      for(int i = 0; i < adj.get(src).size(); i++)
      {
        AdjListNode vertex = adj.get(src).get(i);
 
        // Get adjacent vertex and weight of edge
        int v = vertex.v;
        int w = vertex.weight;
 
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
        if (pathMoreThanKUtil(v, k-w, path))
          return true;
 
        // Backtrack
        path[v] = false;
      }
 
      // If no adjacent could produce longer path, return
      // false
      return false;
    }
 
  }
