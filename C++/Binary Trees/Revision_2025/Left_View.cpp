/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
 */

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        if(!root)
            return {};
            
        vector<int> res;
        
        queue<Node*> q;
        q.push({root});
        
        while(!q.empty()){
            int len = q.size();
            
            for(int i = 0; i < len; i++){
                Node* currNode = q.front();
                q.pop();
                
                if(i==0)
                    res.push_back(currNode->data);
                
                if(currNode->left)
                    q.push(currNode->left);
                
                if(currNode->right)
                    q.push(currNode->right);
            }
        }
        
        return res;
    }
};
