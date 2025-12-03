#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

// start -> head
// next -> link

struct node *head = NULL;

void insert_beg(int n){
    struct node* temp;
    temp = malloc(sizeof(struct node));
    temp->data = n;
    temp->link=NULL;
    
    if(head==NULL){
        head = temp;
    }else{
        temp->link = head;
        head = temp;
    }
}

/*
void travel_forward(){
    struct node * cur;
    cur = head;
    if(head == NULL){
        printf("List is empty");
    }
    else{
        while(cur!=NULL){
            printf("%d",cur->data);
            cur = cur->link;
        }
    }
}
*/
void insert_end(int n){
    
    struct node * temp;
    temp = malloc(sizeof(struct node));
    temp->data = n;
    temp->link = NULL;
    
    struct node* cur = head;
    
    if(head == NULL){
        head = temp;
    }
    while(cur->link != NULL){
        cur = cur->link;
    }
    cur->link = temp;
}

void insert_after(int n, int s){
    struct node*temp , *cur;
    if(head == NULL){
        printf("List empty");
    }else{
        struct node* temp;
        temp = malloc(sizeof(struct node));
        temp->data = n;
        temp->link = NULL;
        
        cur = head; 
        while(cur!= NULL && cur->data != s){
            cur = cur->link;
        }
        if(cur!=NULL){
            temp -> link = cur ->link;
            cur->link = temp;
        }else{
            printf("element not found");
        }
    }
}

int delete_first(){
    int x = -1;
    struct node*temp;
    if(head == NULL){
        printf("List is empty");
    }
    else{
        temp = head;
        x = temp->data;
        head = head->link;
        free(temp);
        temp = NULL;
    }
    return x;
}

int delete_last(){
    int x= -1;
    if(head == NULL){
        printf("List is empty");
    }
    else{
        struct node*temp,*cur;
        if(head->link == NULL){
            temp = head;
            x = temp->data;
            head = NULL;
            
            free(temp);
            temp = NULL;
        }else{
            cur = head;
            while(cur->link->link != NULL){
                cur = cur->link;
            }
            temp = cur->data;
            x = temp ->data;
            cur->link = NULL;
            free(temp);
            temp=NULL;
        }
    }
}
void insert_before(int n, int s){
    
}

int main(){
    insert_beg(10);
    insert_end(20);
    insert_end(30);
    insert_after(50,20);
    
    struct node *p = head;
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->link;
    }
}
