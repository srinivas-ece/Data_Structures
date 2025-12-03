// for doubly
int delete_first(){
    int x = -1;
    struct node*temp;
    if(start == NULL){
        printf("List is empty");
    }else{
        temp = start;
        if(temp->next != NULL){
        x = temp->data;
        start = start->next;
        start->prev = NULL;
        }else{
            x = temp->data;
            start = NULL;
        }
        free(temp);
        temp = NULL;
    }
    return x;
}
