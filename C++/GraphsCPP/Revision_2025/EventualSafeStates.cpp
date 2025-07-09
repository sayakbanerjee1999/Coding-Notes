class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<vector<int>> adjL(n);
        vector<int> indegrees(n, 0);

        // Graph Reversal is the main catch here. 
        // Find Indegrees after reversing the edges of the graph and then normal topo sort
        for(int i = 0; i < n; i++){
            for(auto it: graph[i])
                adjL[it].push_back(i);
        }

        for(int i = 0; i < n; i++){
            for(auto it: adjL[i]){
                indegrees[it]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegrees[i] == 0)
                q.push(i);
        }

        vector<int> res;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            res.push_back(top);
            for(auto it: adjL[top]){
                indegrees[it]--;
                if(indegrees[it] == 0){
                    q.push(it);
                }
            }
        }

        sort(res.begin(), res.end());

        return res;
    }
};
