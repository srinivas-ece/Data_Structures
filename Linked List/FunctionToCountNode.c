void countnode(struct node *start){
    int count = 0;
    if(start==NULL){
        printf("Node is empty");
    }
    struct node *ptr = NULL;
    ptr = start;
    
    while(ptr!=NULL){
        count++;
        ptr = ptr->next;
    }
    printf("%d",count);
}
