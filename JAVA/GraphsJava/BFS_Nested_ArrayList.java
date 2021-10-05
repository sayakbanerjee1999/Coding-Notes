class Solution
{
    //Function to return Breadth First Traversal of given graph.
    public ArrayList<Integer> bfsOfGraph(int V,ArrayList<ArrayList<Integer>> adj)
    {
        // Code here
        //Create the arraylist to finally return
        ArrayList<Integer> res = new ArrayList<Integer>();
        //Make the visited array for keeping track of nodes visited
        boolean visited[] = new boolean[V];
        //A queue for the BFS traversal
        LinkedList<Integer> queue = new LinkedList<Integer>();
        
        //Starting from first node and marking it as visited, then adding it to queue
        visited[0] = true;
        queue.add(0);
        
        //now for all the other nodes
        while (queue.size()!=0){
            //dequeue a vertex from the queue and add to Arraylist to return
            int ans = queue.poll();
            res.add(ans);
            //Get all the neighbours of ans and check if already visited
            //If not visited then mark it visited and add to queue
            ArrayList<Integer> n = adj.get(ans);
            Iterator i = n.iterator();
            while (i.hasNext()){
                int nextNode = (Integer)i.next();
                if (!visited[nextNode]){
                    visited[nextNode] = true;
                    queue.add(nextNode);
                }
            }
            
        }
        
    return res;
    
    }
}
