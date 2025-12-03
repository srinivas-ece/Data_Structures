int delete_first(){
    int x=-1;
    struct node *temp;
    if(start==NULL){
        printf("List is empty");
    }else{
        temp = start;
        x = temp->data;
        start = start->next;
        free(temp);
        temp = NULL;
    }
    return x;
}
