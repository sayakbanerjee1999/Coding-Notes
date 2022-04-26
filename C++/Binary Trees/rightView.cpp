class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        
        if(!root)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                // Only push first value of each level in the result
                if(i == 0){
                    res.push_back(temp->val);
                    // break;
                }
                
                // First push in right node then left
                if(temp->right)
                    q.push(temp->right);
                
                if(temp->left)
                    q.push(temp->left);
            }
        }
        
        return res;
    }
};
