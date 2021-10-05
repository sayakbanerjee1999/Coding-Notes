Node* insert(Node* node, int data)
{
    // Your code here
    if (node == NULL) 
        return node = new Node(data);
        
   if (data < node->data)
        node->left  = insert(node->left, data);
        
    else if (data > node->data)
        node->right = insert(node->right, data);
        
    return node;
}
