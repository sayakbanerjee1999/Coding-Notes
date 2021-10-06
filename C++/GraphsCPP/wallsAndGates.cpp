Walls and Gates - LeetCode Prem

void wallsAndGates(vector<vector<int>> &rooms){
  for(int i = 0; i < rooms.size(); i++){
    for(int j = 0; j < rooms[i].size(); j++){
      if(rooms[i][j] == 0)
        dfs(i, j, 0, rooms);
    }
  }
}

void dfs(int i, int j, int dist, vector<vector<int>> &rooms){
  if(i < 0  ||  i >= rooms.size()  ||  j < 0  ||  j >= rooms[0].size())
    return;
   
  if(rooms[i][j] < dist  ||  rooms[i][j] == -1)
    return;
    
  rooms[i][j] = dist;
  
  dfs(i+1, j, dist+1, rooms);
  dfs(i-1, j, dist+1, rooms);
  dfs(i, j+1, dist+1, rooms);
  dfs(i, j-1, dist+1, rooms);
}
