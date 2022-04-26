vector <int> diagonalSum(Node* root) {
    // Add your code here
    vector<int> res;
    
    if(!root)
        return res;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int sum = 0;
        
        int size = q.size();
        
        for(int i = 0; i < size; i++){
            Node* temp = q.front();
            q.pop();
            
            sum += temp->data;
            
            if(temp->left)
                q.push(temp->left);
            
            while(temp->right){
                sum += temp->right->data;
                
                temp = temp->right;
                
                if(temp->left)
                    q.push(temp->left);
            }
        }
        
        res.push_back(sum);
    }
    
    return res;
}
