class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
            
        if(!root)
            return res;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> store;
            
            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                store.push_back(temp->val);
                
                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
            }
            
            res.push_back(store);
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
