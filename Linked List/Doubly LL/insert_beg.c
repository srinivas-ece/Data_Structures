void insert_beg(int n){
    struct node*temp;
    temp = malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    temp->prev = NULL;
    
    if(start==NULL){
        start = temp;
    }
    else{
        temp->next = start;
        start -> prev = temp; 
        start = temp ; // here we are moving our pointer from start to the temp which is our first node now 
    }
}
