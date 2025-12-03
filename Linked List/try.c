#include<stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
}*start;

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

void travel_forward(){
    struct node *cur;
    cur = start;
    if(start==NULL){
        printf("Empty List");
    }else{
        while(cur!=NULL){
            printf("%d",cur->data);
            cur = cur->next;
        }
    }
}

void insert_end(int n){
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    
    struct node *cur = start;
    if(start=NULL){
        start = temp;
    }else{
        while(cur->next!=NULL){
            cur = cur->next;
        }
        cur->next = temp;
    }
}

int main()
{
    struct node * start = malloc (sizeof(struct node));

    start = NULL;
    
    /*struct node * curr = malloc (sizeof(struct node));
    curr->data = 17;
    curr->next = NULL;
    start->next = curr;
    */
    
    insert_beg(1);
    insert_beg(2);
    insert_beg(3);
    insert_beg(4);
    //insert_end(5);
    travel_forward();
    return 0;
}
