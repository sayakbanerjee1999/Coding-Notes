class Solution {
    // Kahn's algorithm
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indegrees(numCourses, 0);

        for(auto it: prerequisites){
            adjList[it[1]].push_back(it[0]);
            indegrees[it[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegrees[i] == 0)
                q.push(i);
        }

        vector<int> res;
        while(!q.empty()){
            int course = q.front();
            q.pop();

            res.push_back(course);
            for(auto it: adjList[course]){
                indegrees[it]--;
                if(indegrees[it] == 0)
                    q.push(it);
            }
        }

        if(res.size() != numCourses)      // If size is not equal to the initial, it means that it is not a DAG. It has a cycle.
            return {};
        
        return res;
    }
};
