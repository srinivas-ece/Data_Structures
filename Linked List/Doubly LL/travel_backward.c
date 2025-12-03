// travel Backward Doubly LL
void travel_backward(){
    struct node *cur;
    if(start==NULL){
        printf("List is emoty");
    }else{
        cur = start;
        while(cur->next != NULL){
            cur = cur -> next;
        }while(cur!= NULL){
            printf("%d",cur->data);
            cur = cur->prev;
        }
    }
}
