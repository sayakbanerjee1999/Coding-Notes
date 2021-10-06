Minimum Height Trees - LeetCode 310

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        
        vector<int> graph[n];
        vector<int> inDegree(n,0);
        
        for(auto i: edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
            inDegree[i[0]]++;
            inDegree[i[1]]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==1)
                q.push(i);
        }
        
        while(n>2){
            int size=q.size();
            n-=size;
            
            for(int i=0;i<size;i++){
                int temp=q.front();
                q.pop();
                
                for(auto x:graph[temp]){
                    inDegree[x]--;
                    if(inDegree[x]==1)
                        q.push(x);
                }
            }
        }
        
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }
};
