Course Schedule II - LeetCode 210
  
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> in(numCourses, 0);
        vector<int> res;
        
        for(auto x: prerequisites){
            adj[x[1]].push_back(x[0]);
            in[x[0]]++;
        }
        
        queue<int> q;
        int coursesProcessed = 0;
        for(int i = 0; i < numCourses; i++){
            if(in[i]==0){
                coursesProcessed++;
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int temp = q.front();
            res.push_back(temp);
            q.pop();
            
            for(auto x: adj[temp]){
                in[x]--;
                
                if(in[x]==0){
                    coursesProcessed++;
                    q.push(x);
                }
            }
        }
        
        if (numCourses != coursesProcessed)
            return {};
        else
            return res;    
        
    }
};
