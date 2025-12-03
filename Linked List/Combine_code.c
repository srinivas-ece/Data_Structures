#include<stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
}*start = NULL;

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

void insert_end(int n){
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    
    struct node *cur = start;
    if(start==NULL){
        start = temp;
    }else{
        while(cur->next!=NULL){
            cur = cur->next;
        }
        cur->next = temp;
    }
}

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

void travel_forward(){
    struct node *cur;
    cur = start;
    if(start==NULL){
        printf("Empty List");
    }else{
        while(cur!=NULL){
            printf("%d ",cur->data);
            cur = cur->next;
        }
    }
}

int main()
{
    struct node * start = malloc (sizeof(struct node));
    

    insert_end(2);
    insert_end(3);
    insert_end(4);
    insert_end(5);
    insert_after(1,5);
    delete_first();
    //delete_last();
    travel_forward();
    return 0;
}
