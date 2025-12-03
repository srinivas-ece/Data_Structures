#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next; 
};

struct node *head;
struct node *first;
struct node *second;

void traverse(struct node *ptr){
    while(ptr!=NULL){
        printf("%d",ptr->data);  
        ptr = ptr->next;
    }
}

int main(){
    head = (struct node*)malloc(sizeof(struct node));
    first = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    
    head -> data = 7;
    head -> next = first;
    first -> data = 10;
    first -> next = second;
    second -> data = 12;
    second -> next = NULL;
    
    traverse(head);
    
}
