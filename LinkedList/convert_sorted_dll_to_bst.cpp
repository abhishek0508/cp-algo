// time complexity -> O(n) space O(1)
Node* convertdllbst(Node *head){
    int n = countnodes(head);
    return convert(head,n);
}

Node *convert(Node *head, int n){
    if(n<=0){
        return NULL;
    }

    Node *left = convert(head,n/2);
    Node *root = head;

    root->prev = left;

    head = head->next;

    root->next = convert(head,n-(n/2)-1);
    return root;
}

// naive
Node* convertdllbst(Node *head){
    Node *mid_node = mid(head);
    Node *root = mid_node;
    root->prev = convertdllbst(head->prev);
    root->next = convertdllbst(head->next);
}