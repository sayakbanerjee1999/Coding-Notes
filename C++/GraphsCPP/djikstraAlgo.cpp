Djikstra Algorithm - GFG

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
    // First Vertex is stored followed by distance; Neighbour[0] <- Vertex, Neighbour[1] <- dist
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> distance(V, INT_MAX);
        distance[S] = 0;
        
        set<pair<int, int>> s;
        s.insert({0, S});
        
        while(!s.empty()){
            auto it = s.begin();
            pair<int, int> num = *it;
            
            int dist = num.first;
            int v = num.second;
            
            s.erase(it);
            
            for(auto neighbour: adj[v]){
                if(dist + neighbour[1] < distance[neighbour[0]]){
                    auto ii = s.find({distance[neighbour[0]], neighbour[0]});
                    
                    if(ii == s.end()){              // Not found; Insert directly 
                        s.insert({dist + neighbour[1], neighbour[0]});
                        distance[neighbour[0]] = dist + neighbour[1];
                    } 
                    
                    else{                           // Remove then insert
                        s.erase(ii);
                        s.insert({dist + neighbour[1], neighbour[0]});
                        distance[neighbour[0]] = dist + neighbour[1];
                    }
                }
            }
        }
        
        return distance;
    }
};
