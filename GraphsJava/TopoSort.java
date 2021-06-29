class Solution
{
    //Function to return list containing vertices in Topological order. 
    static int[] topoSort(int N, ArrayList<ArrayList<Integer>> adj) 
    {
        // add your code here
        int topo[] = new int[N]; 
        int indegree[] = new int[N]; 
        for(int i = 0;i<N;i++) {
            for(Integer it: adj.get(i)) {
                indegree[it]++; 
            }
        }
        
        Queue<Integer> q = new LinkedList<Integer>(); 
        for(int i = 0;i<N;i++) {
            if(indegree[i] == 0) {
                q.add(i); 
            }
        }
        int cnt = 0;
        while(!q.isEmpty()) {
            Integer node = q.poll(); 
            topo[cnt] = node;
            cnt++; 
            
            for(Integer it: adj.get(node)) {
                indegree[it]--; 
                if(indegree[it] == 0) {
                    q.add(it); 
                }
            }
        }
        // if(cnt == N) return false; 
        // return true; 
        return topo;
    }
}
