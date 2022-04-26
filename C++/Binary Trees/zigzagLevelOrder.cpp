class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if(!root)
            return res;
        
        int levelNow = 1;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            vector<int> store;
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                store.push_back(temp->val);
                
                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
            }
            
            if(levelNow%2 == 0)
                reverse(store.begin(), store.end());
            
            res.push_back(store);
            levelNow++;
        }
        
        return res;
    }
};
