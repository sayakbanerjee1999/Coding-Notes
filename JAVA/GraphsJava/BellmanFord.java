class Solution
{
    public int isNegativeWeightCycle(int V, int[][] graph)
    {
        //code here
        // Initialize distance of all vertices as infinite.
        int []dis = new int[V];
        for (int i=0; i<V; i++)
            dis[i] = Integer.MAX_VALUE;
     
        // initialize distance of source as 0
        dis[0] = 0;
        //Get number of edges
        int E = graph.length;
        // Relax all edges |V| - 1 times. 
        for (int i=0; i<V-1; i++)
        {
            for (int j = 0; j < E; j++)
            {
                if (dis[graph[j][0]] != Integer.MAX_VALUE && dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]])
                    dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
            }
        }
    int ans = 0;
    // check for negative-weight cycles.
    for (int i=0; i<E; i++)
    {
        int x = graph[i][0];
        int y = graph[i][1];
        int weight = graph[i][2];
        if (dis[x] != Integer.MAX_VALUE &&
                dis[x] + weight < dis[y])
            return 1;
    }
    return ans;
 
        
    }
}
