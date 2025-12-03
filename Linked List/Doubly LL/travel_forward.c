void travel_forward(){
    struct node *cur;
    cur = start;
    if(start==NULL){
        printf("List is empty");
    }else{
        while(cur!=NULL){
            printf("%d",cur->data);
            cur = cur->next;
        }
    }
}
