class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        // Find the friends of the given ID at a level
        int n = friends.size();
        
        queue<int> q;
        vector<int> visited(n, 0);
        q.push(id);
        visited[id] = 1;

        // IMPORTANT CODE FOR LEVEL ORDER TRAVERSAL OF THE GRAPH
        while(level!=0){
            // Take everything at a level at once (For correct)
            int size = q.size();
            while(size--){
                int ele = q.front();
                q.pop();

                for(auto it: friends[ele]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = true;
                    }
                }
            }
            
            level--;
        }

        vector<int> friendsLevel;
        while(!q.empty()){
            friendsLevel.push_back(q.front());
            q.pop();
        }

        unordered_map<string, int> hashMap;
        for(int i = 0; i < friendsLevel.size(); i++){
            for(auto movie: watchedVideos[friendsLevel[i]]){
                if(hashMap.find(movie)==hashMap.end())
                    hashMap[movie] = 1;
                else
                    hashMap[movie]++;
            }
        }

        vector<pair<string, int>> movies(hashMap.begin(), hashMap.end());

        // Step 2: Sort by frequency, then alphabetically
        sort(movies.begin(), movies.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second)
                return a.first < b.first; // Alphabetical order
            return a.second < b.second;   // Frequency order
        });

        // Step 3: Extract sorted video titles
        vector<string> result;
        for (auto& it : movies)
            result.push_back(it.first);

        return result;
    }
};
