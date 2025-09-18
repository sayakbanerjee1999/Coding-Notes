class Solution {
public:
    bool getPath(TreeNode* root, vector<int>& arr, int x) {
        if (!root) {
            return false;
        }

        // Add the current node's value to the path vector
        arr.push_back(root->val);

        // If the current node's value is equal to the target value 'x', return true
        if (root->val == x) {
            return true;
        }

        // Recursively search for the target value 'x' in the left and right subtrees
        if (getPath(root->left, arr, x) || getPath(root->right, arr, x)) {
            return true;
        }

        // If the target value 'x' is not found in the current path, backtrack
        arr.pop_back();
        return false;
    }

    vector<int> solve(TreeNode* root, int B) {
        // Initialize an empty vector to store the path
        vector<int> arr;

        if (root == NULL) 
            return arr;
        getPath(root, arr, B);

        return arr;
    }
};
