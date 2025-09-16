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
    vector<int> bottomView(Node *root) {
        // Your Code Here
        vector<int> res;
        map<int, int> map;
        
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            Node* curr_node = it.first;
            int vertical_line = it.second;
            
            // Keep Updating as we take the last node for a vertical line
            map[vertical_line] = curr_node->data;
            
            
            if(curr_node->left)
                q.push({curr_node->left, vertical_line - 1});
            
            if(curr_node->right)
                q.push({curr_node->right, vertical_line + 1});
        }
        
        for(auto it: map)
            res.push_back(it.second);
        
        return res;
    }
};
