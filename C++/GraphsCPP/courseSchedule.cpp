Course Schedule - LeetCode 207
  
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> in(numCourses, 0);
        
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
            q.pop();
            
            for(auto x: adj[temp]){
                in[x]--;
                
                if(in[x]==0){
                    coursesProcessed++;
                    q.push(x);
                }
            }
        }
        
        return coursesProcessed == numCourses;
    }
};
