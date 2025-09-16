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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};

        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);

        int currLevel = 0;
        while(!q.empty()){
            int len = q.size();
            vector<int> lvl;

            for(int i = 0; i < len; i++){
                TreeNode* currNode = q.front();
                q.pop();

                lvl.push_back(currNode->val);

                if(currNode->left)
                    q.push(currNode->left);
                
                if(currNode->right)
                    q.push(currNode->right);
            }

            if(currLevel%2==1){
                reverse(lvl.begin(), lvl.end());
            }

            res.push_back(lvl);
            currLevel+=1;
        }

        return res;
    }
};
