class solve 
{
    //Function to determine if graph can be coloured with at most M colours such
    //that no two adjacent vertices of graph are coloured with same colour.
    public static boolean graphColoring(List<Integer>[] G, int[] color, int ver, int C) 
    {
        // Your code here
        int V = G.size();
        //initializing all to 0
        for (int i= 0;i<V;i++)
            color[i] = 0;
 
        if (!graphColoringUtil(G, color, 0, C))
        {
            return false;
        }
 
        return true;
        
    }
    
    
    static boolean isSafe(int v, List<Integer>[] G, int color[], int c)
    {
        int V = G.size();
        for (int i=0; i<V; i++)
            if (
                graph[v].contains(i) && c == color[i])
                return false;
        return true;
    }
 

    static boolean graphColoringMain(List<Integer>[] G, int color[], int v, int m)
    {
        
        int V = G.size();
        if (v == V)
            return true;
 
        //Consider this vertex v and try different colors 
        for (int c=1; c<=m; c++)
        {
            //Check if assignment of color c to v is fine
            if (isSafe(v, G, color, c))
            {
                color[v] = c;
 
                //assign to rest of the vertices
                if (
                    graphColoringMain(G, color, v + 1, m))
                    return true;
 
                // if no solution then leave it backtrack
                color[v] = 0;
            }
        }
 
        return false;
    }
}
