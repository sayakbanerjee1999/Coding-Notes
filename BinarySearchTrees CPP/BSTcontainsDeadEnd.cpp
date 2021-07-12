bool solve(Node* root, int lBound, int uBound){
    if(!root)
        return false;
    
    // If lBound and uBound are same. You cannot insert any node to it
    // Hence it contains dead end
    if(lBound==uBound)
        return true;
    
    return solve(root->left, lBound, root->data-1) || solve(root->right, root->data+1, uBound);
}

bool isDeadEnd(Node *root){
    //Your code here
    return solve(root, 1, INT_MAX);
}
