LEETCODE - 399 (HARD)

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    
        int en = equations.size();
        int qn = queries.size();
        
        unordered_map<string, vector<pair<string, double>>> hashmap;
        
        for(int i = 0; i < en; i++){
            hashmap[equations[i][0]].push_back({equations[i][1], values[i]});
            hashmap[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }
        
        vector<double> res;
        
        for(int i = 0; i < qn; i++){
            string src = queries[i][0];
            string des = queries[i][1];
            
            // If source node itself is not available in map then return -1
            if(hashmap.find(src) == hashmap.end()){
                res.push_back(-1.0);
                continue;
            }
            
            queue<pair<string, double>> q;
            q.push(pair{src, 1.0});
            int flag = 0;
         
            unordered_set<string> visited;
            visited.insert(src);
            
            while(!q.empty()){
                auto temp = q.front();
                q.pop();
                
                string node = temp.first;
                double val = temp.second;
                
                if(node == des){
                    res.push_back(val);
                    flag = 1;
                    break;
                }
                
                for(auto p: hashmap[node]){
                    // If not visited push in queue
                    if(visited.find(p.first) == visited.end()){
                        q.push({p.first, val * p.second});
                        visited.insert(p.first);
                    }
                }
            }
            
            if(!flag)
                res.push_back(-1.0);
        }
        
        return res;
    }
};
