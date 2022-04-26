vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> res;
   if(root == NULL)
    return res;

    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            Node* temp = q.front();
            
            if(i==0)
                res.push_back(temp->data);
            
            if(temp->left)
                q.push(temp->left);
            
            if(temp->right)
                q.push(temp->right);
            
            q.pop();
        }
    }
    
    return res;
}
