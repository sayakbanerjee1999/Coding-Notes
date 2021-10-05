vector<int> solve(Node* root){
    if(root==NULL)                              // If root is NULL. BST of size 0
        return {1, 0, INT_MAX, INT_MIN};
    
    // Leaf Node
    if(root->left==NULL && root->right==NULL)
        return {1, 1, root->data, root->data};
    
    vector<int> l = solve(root->left);
    vector<int> r = solve(root->right);
    
    //For a root node to become BST. Left and Right Subtrees must be BSTs 
    //Max value from left subtree must be less than root node value
    //Min value from right subtree must be greater than root node value
    if(l[0]==1 && r[0]==1){
        if(root->data > l[3]  &&  root->data < r[2]){
            int x = l[2];
            int y = r[3];
            
            if(x==INT_MAX)  
                x = root->data;
            
            if(y==INT_MIN)
                y = root->data;
            
            return {1, l[1]+r[1]+1, x, y};
        }
    }
    
    return {0, max(l[1], r[1]), 0, 0};
}


int largestBst(Node *root)
{
	//Your code here
	vector<int> res = solve(root);
	
	return res[1];
}
