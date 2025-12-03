void insert_end(int n){
    struct node*temp;
    temp = malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    temp->prev = NULL;
    
    struct node* cur = start;
    if(start==NULL){
        start = temp;
    }else{
        cur = start;
        while(cur->next != NULL){
            cur = cur->next;
            temp ->prev = cur;
        }
        cur->next = temp;
    }
}
