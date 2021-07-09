int helpaterp(vector<vector<int>> hospital)
{
    //code here
    int n = hospital.size();
    int m = hospital[0].size();
    
    // Serves as the visited as well
    vector<vector<int>> infectionTime(n, vector<int>(m, -1));
    
    queue<pair<pair<int, int>, int>> q;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(hospital[i][j] == 2){
                q.push({{i, j}, 0});
                infectionTime[i][j] = 0;
            }
        }
    }
    
    vector<pair<int, int>> direction = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    
    while(!q.empty()){
        auto current = q.front();
        q.pop();
 
        for (auto it : direction) {
            int i = current.first.first + it.first;
            int j = current.first.second + it.second;
 
            // Search within bounds
            if (i < 0 || j < 0 || i >= n || j >= m || hospital[i][j] != 1 || infectionTime[i][j] != -1)
                continue;
 
            // Push the infected neighbour into queue
            q.push({{i, j}, current.second + 1});
            infectionTime[i][j] = current.second + 1;
        }
    }
    

    int maxTime = 0;
    int flag = 0;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (hospital[i][j] != 1)
                continue;
 
            if (hospital[i][j] == 1 && infectionTime[i][j] == -1) {
                return -1;
            }
 
            maxTime = max(maxTime, infectionTime[i][j]);
        }
    }
 
    return maxTime;
}