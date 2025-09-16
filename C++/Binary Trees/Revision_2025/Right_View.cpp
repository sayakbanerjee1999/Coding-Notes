/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
            return {};
        
        vector<vector<int>> res;

        queue<TreeNode*> q;
        q.push({root});

        while(!q.empty()){
            int len = q.size();
            vector<int> currLev;

            for(int i = 0; i < len; i++){
                TreeNode* currNode = q.front();
                q.pop();

                currLev.push_back(currNode->val);
                // You can also just push the first val. Reduces complexity

                if(currNode->right)
                    q.push(currNode->right);
                
                if(currNode->left)
                    q.push(currNode->left);
            }

            res.push_back(currLev);
        }

        vector<int> final;
        for(auto it: res)
            final.push_back(it[0]);

        return final;
    }
};
