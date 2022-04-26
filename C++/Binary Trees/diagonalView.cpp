vector<int> diagonal(Node *root)
{
    // your code here
    vector<int> res;
   
    if(!root)
        return res;
        
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        res.push_back(temp->data);
        
        if(temp->left)
            q.push(temp->left);
        
        while(temp->right){
            res.push_back(temp->right->data);
            
            temp = temp->right;
            
            if(temp->left)
                q.push(temp->left);
        }
    }
    
    return res;
}
