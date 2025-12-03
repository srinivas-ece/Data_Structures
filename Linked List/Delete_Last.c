int delete_last(){
    int x=-1;
    
    if(start==NULL){
        printf("List is empty");
    }else{
        struct node *temp,*cur;
        if(start->next == NULL){
            temp = start;
            x = temp->data;
            start = NULL;
            free(temp);
            temp = NULL;
        }else{
            cur = start;
            while(cur->next->next!=NULL){
                cur = cur->next;
            }
            temp = cur->next;
            x = temp -> data;
            cur -> next = NULL;
            free(temp);
            temp = NULL;
        }
    }
    
}
