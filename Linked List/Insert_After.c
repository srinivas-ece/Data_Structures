void insert_after(int n,int s){
    struct node *temp,*cur;
    if(start == NULL){
        printf("Empty");
    }else{
        temp = malloc(sizeof(struct node));
        temp->data = n;
        temp->next = NULL;
        cur=start;
        while(cur!=NULL && cur-> data != s){
            cur = cur->next;
        }
        if(cur!=NULL){
            temp->next = cur->next;
            cur->next = temp;
        }
        else{
            printf("Element not found");
        }
    }
}
