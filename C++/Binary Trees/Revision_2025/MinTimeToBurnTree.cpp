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
    TreeNode* parentMapF(TreeNode* root, map<TreeNode*, 
                        TreeNode*>& parentMap,
                        int start){
        queue<TreeNode*> q;
        q.push(root);

        TreeNode* res = NULL;
        
        while(!q.empty()){
            TreeNode* currNode = q.front();
            q.pop();

            if(currNode->val == start)
                res = currNode;
            
            if(currNode->left){
                q.push(currNode->left);
                parentMap[currNode->left] = currNode;
            }

            if(currNode->right){
                q.push(currNode->right);
                parentMap[currNode->right] = currNode;
            }
        }

        return res;
    }
            
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> parentMap;
        // Get Parent Map so that you can travel up the tree as well
        TreeNode* target = parentMapF(root, parentMap, start);

        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        int timer = 0;
        while(!q.empty()){
            int size = q.size();
            int flag = 0;

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]){
                    flag = 1;
                    q.push(node->left);
                    visited[node->left] = true;
                }

                if(node->right && !visited[node->right]){
                    flag = 1;
                    q.push(node->right);
                    visited[node->right] = true;
                }

                if(parentMap[node] && !visited[parentMap[node]]){
                    flag = 1;
                    q.push(parentMap[node]);
                    visited[parentMap[node]] = true;
                }
            }

            // If we visited any node then increment timer.
            if(flag == 1)
                timer += 1;
        }

        return timer;
    }
};
