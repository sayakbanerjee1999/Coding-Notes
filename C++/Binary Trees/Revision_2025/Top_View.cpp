/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> res;
        map<int, int> map;
        
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            Node* curr_node = it.first;
            int vertical_line = it.second;
            
            // Only push the first value for a vertical line to the map
            // Do not overwrite
            if(map.find(vertical_line) == map.end())
                map[vertical_line] = curr_node->data;
            
            // Go left
            if(curr_node->left)
                q.push({curr_node->left, vertical_line-1});
            
            // Go right
            if(curr_node->right)
                q.push({curr_node->right, vertical_line+1});
                
        }
        
        for(auto it: map){
            res.push_back(it.second);
        }
        
        return res;
    }
};
