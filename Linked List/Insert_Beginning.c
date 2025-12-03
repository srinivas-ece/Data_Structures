void insert_beg(int n){
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp -> data = n;
    temp -> next = NULL;
    
    if(start==NULL){
        start = temp;
    }else{
        temp -> next = start;
        start = temp;
    }
}
