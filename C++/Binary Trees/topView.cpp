class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root){
        vector<int> res;
        
        if(!root)
            return res;
        
        map<int, int> mapHeight;
        queue<pair<int, Node*>> q;
        q.push({0, root});
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                Node* temp = q.front().second;
                int height = q.front().first;
                q.pop();
                
                // Only append the first node respect to individual height
                if(mapHeight.find(height) == mapHeight.end())
                    mapHeight[height] = temp->data;
                    
                if(temp->left)
                    q.push({height-1, temp->left});
                    
                if(temp->right)
                    q.push({height+1, temp->right});
            }
        }
        
        for(auto it: mapHeight)
            res.push_back(it.second);
            
        return res;
    }
};
