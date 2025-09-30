/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class NodeValue {
public:
    int minVal, maxVal, maxSize;
    
    NodeValue(int minVal, int maxVal, int maxSize){
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->maxSize = maxSize;
    }
};

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    NodeValue helper(Node* root){
        // Set min to max and max to min for ease of comparison
        if(root==NULL) return NodeValue(INT_MAX, INT_MIN, 0);
        
        NodeValue left = helper(root->left);
        NodeValue right = helper(root->right);
        
        // Valid Binary Tree
        if(left.maxVal < root->data && root->data < right.minVal)
            // MinVal = min(root->val, left.minVal) Similarly MaxVal = max(right.maxVal, root->val)
            return NodeValue(min(root->data, left.minVal), 
                             max(root->data, right.maxVal),
                             1+left.maxSize+right.maxSize
                            );
        
        // If invalid send min = int_min and max = int_max so that no comparison is possible further
        return NodeValue(INT_MIN, INT_MAX, 
                        max(left.maxSize, right.maxSize));
    }
    
    int largestBst(Node *root) {
        // Your code here
        return helper(root).maxSize;
    }
};
