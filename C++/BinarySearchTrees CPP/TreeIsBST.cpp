void util(Node* root, Node* &prev, bool &flag){
        if(!root)
            return;
        
        util(root->left, prev, flag);
        
        if(prev != NULL  &&  root->data <= prev->data){
            flag = 0;
            return;
        }
        
        prev = root;            //If condition not satisfied continue 
        
        util(root->right, prev, flag);
        
        return;
    }
    
    bool isBST(Node* root){
        // Your code here
        bool flag = 1;
        Node *prev = NULL;
        
        util(root, prev, flag);
        
        return flag;
    }
