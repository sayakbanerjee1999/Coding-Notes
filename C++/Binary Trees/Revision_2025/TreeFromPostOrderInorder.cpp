/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // code here
        map<int, int> set;
        
        for(int i = 0; i < inorder.size(); i++){
            set[inorder[i]] = i;
        }
        
        Node* root = helper(postorder, 0, postorder.size()-1,
                                inorder, 0, inorder.size()-1, set);
                                
        return root;
    }
    
    Node* helper(vector<int> &postorder, int postStart, int postEnd,
                 vector<int> &inorder, int inStart, int inEnd, 
                 map<int, int> &set){
                     
        if(postStart > postEnd || inStart > inEnd) return NULL;
        
        Node *root = new Node(postorder[postEnd]);
        int inRootPos = set[root->data];
        int nodesLeft = inRootPos - inStart;
        
        // note postEnd index
        root->left = helper(postorder, postStart, postStart+nodesLeft-1,
                            inorder, inStart, inRootPos-1, set);
        // Note postStart index
        root->right = helper(postorder, postStart+nodesLeft, postEnd-1,
                             inorder, inRootPos+1, inEnd, set);
        
        return root;
    }
};
