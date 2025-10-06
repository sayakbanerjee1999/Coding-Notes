Node* merge2LL(Node* list1, Node* list2) {
    // Create a dummy node to serve
    // as the head of the merged list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    // Traverse both lists simultaneously
    while (list1 != nullptr && list2 != nullptr) {
        // Compare elements of both lists and
        // link the smaller node to the merged list
        if (list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        // Move the temporary pointer
        // to the next node
        temp = temp->next; 
    }

    // If any list still has remaining
    // elements, append them to the merged list
    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
    // Return the merged list starting 
    // from the next of the dummy node
    return dummyNode->next;
}

Node* sortLL(Node* head){
    if(head == NULL || head->next == NULL) return head;
  
    Node* middle = findMiddle(head);       // Use fastPtr slowPtr; slowPtr = head; fastPtr = head->next
    Node* right = middle->next;
    middle->next = NULL;
    Node* first = head;
  
    Node* first = sortLL(first);
    Node* second = sortLL(right);

    return merge2LL(first, second);
}
