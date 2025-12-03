void insert_end(int n){
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    
    struct node *cur = start;
    if(start==NULL){
        start = temp;
    }else{
        while(cur->next!=NULL){
            cur = cur->next;
        }
        cur->next = temp;
    }
}
