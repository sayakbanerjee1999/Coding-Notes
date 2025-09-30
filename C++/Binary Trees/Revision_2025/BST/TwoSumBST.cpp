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
class BSTIterator {
private:
    bool reverse = false;
    stack<TreeNode*> st;

    void pushAll(TreeNode* root){
        if(reverse){
            while(root){
                st.push(root);
                root = root->right;
            }
        } else {
            while(root){
                st.push(root);
                root = root->left;
            }
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse){
        // Constructor initialize
        reverse = isReverse;
        pushAll(root);
    }

    int next(){
        TreeNode* fr = st.top();
        st.pop();

        if(reverse){
            if(fr->left){
                pushAll(fr->left);
            }
        } else {
            if(fr->right){
                pushAll(fr->right);
            }
        }

        return fr->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator* l = new BSTIterator(root, false);
        BSTIterator* r = new BSTIterator(root, true);

        int leftEle = l->next();
        int rightEle = r->next();

        while(leftEle < rightEle){
            if(leftEle + rightEle == k) return true;
            else if(leftEle + rightEle < k) leftEle = l->next();
            else rightEle = r->next();
        }
        delete l;
        delete r;
        return false;
    }

    // void inorder(TreeNode* root, vector<int> &res){
    //     if(root == NULL) return;

    //     inorder(root->left, res);
    //     res.push_back(root->val);
    //     inorder(root->right, res);
    // }

    // bool findTarget(TreeNode* root, int k) {
    //     vector<int> res;
    //     inorder(root, res);

    //     int i = 0;
    //     int j = res.size()-1;

    //     while (i < j){
    //         int sum = res[i] + res[j];

    //         if(sum == k){
    //             return true;
    //         }
    //         else if(sum < k){
    //             i++;
    //         }
    //         else{
    //             j--;
    //         }
    //     }

    //     return false;
    // }
};
