All Paths from Source to Target in a DAG - LeetCode 797
  
class Solution {
public:
    vector<vector<int>> paths;
    
    void dfs(int v, vector<vector<int>>& graph, vector<int> p){
        p.push_back(v);
        
        if(v == graph.size()-1){
            paths.push_back(p);
            p.clear();
        }
        
        for(int i = 0; i < graph[v].size(); i++){
            dfs(graph[v][i], graph, p);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> p;
        
        dfs(0, graph, p);
        
        return paths;
    }
};
