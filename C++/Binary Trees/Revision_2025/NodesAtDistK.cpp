/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parentMapF(TreeNode* root, map<TreeNode*, TreeNode*> &parentMap) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* currNode = q.front();
            q.pop();

            if(currNode->left){
                parentMap[currNode->left] = currNode;
                q.push(currNode->left);
            }

            if(currNode->right){
                parentMap[currNode->right] = currNode;
                q.push(currNode->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        map<TreeNode*, bool> visited;
        
        // Get Parent so that you can travel up the tree as well
        map<TreeNode*, TreeNode*> parentMap;
        parentMapF(root, parentMap);

        queue<TreeNode*> q;
        q.push({target});
        visited[target] = true;

        int currLevel = 0;

        while(!q.empty()){
            int size = q.size();
            if(currLevel == k)
                break;
            
            for(int i = 0; i < size; i++){
                TreeNode* currNode = q.front();
                q.pop();

                if(currNode->left && !visited[currNode->left]){
                    visited[currNode->left] = true;
                    q.push(currNode->left);
                }

                if(currNode->right && !visited[currNode->right]){
                    visited[currNode->right] = true;
                    q.push(currNode->right);
                }

                if(parentMap[currNode] && !visited[parentMap[currNode]]){
                    visited[parentMap[currNode]] = true;
                    q.push(parentMap[currNode]);
                }
            }

            currLevel += 1;
        }

        // Get the nodes from the current queue
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            res.push_back(node->val);
        }

        return res;
    }
};
