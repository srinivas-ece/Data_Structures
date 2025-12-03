#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

// head -> start
// link -> next

struct node *start = NULL;

void insert_beg(int n){
    struct node* temp;
    temp = malloc(sizeof(struct node));
    temp->data = n;
    temp->next=NULL;
    
    if(start==NULL){
        start = temp;
    }else{
        temp->next = start;
        start = temp;
    }
}

/*
void travel_forward(){
    struct node * cur;
    cur = start;
    if(start == NULL){
        printf("List is empty");
    }
    else{
        while(cur!=NULL){
            printf("%d",cur->data);
            cur = cur->next;
        }
    }
}
*/

void insert_end(int n){
    struct node * temp;
    temp = malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    
    struct node* cur = start;
    
    if(start == NULL){
        start = temp;
    } else {
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = temp;
    }
}

void insert_after(int n, int s){
    struct node*temp , *cur;
    if(start == NULL){
        printf("List empty");
    }else{
        temp = malloc(sizeof(struct node));
        temp->data = n;
        temp->next = NULL;
        
        cur = start; 
        while(cur!= NULL && cur->data != s){
            cur = cur->next;
        }
        if(cur!=NULL){
            temp -> next = cur ->next;
            cur->next = temp;
        }else{
            printf("element not found");
        }
    }
}

int delete_first(){
    int x = -1;
    struct node*temp;
    if(start == NULL){
        printf("List is empty");
    }
    else{
        temp = start;
        x = temp->data;
        start = start->next;
        free(temp);
        temp = NULL;
    }
    return x;
}

int delete_last(){
    int x= -1;
    if(start == NULL){
        printf("List is empty");
    }
    else{
        struct node*temp,*cur;
        if(start->next == NULL){
            temp = start;
            x = temp->data;
            start = NULL;
            
            free(temp);
            temp = NULL;
        }else{
            cur = start;
            while(cur->next->next != NULL){
                cur = cur->next;
            }
            temp = cur->next;
            x = temp ->data;
            cur->next = NULL;
            free(temp);
            temp=NULL;
        }
    }
    return x;
}

void insert_before(int n, int s){
    struct node*temp , *cur;
    if(start==NULL){
        printf("List is empty");
    }else{
        temp = malloc(sizeof(struct node));
        temp->data = n;
        temp->next = NULL;
        
        if(start->data == s){
            temp->next = start;
            start = temp;
        }else{
            cur = start;
            while(cur->next != NULL && cur->next->data != s){
                cur = cur->next;
            }
            if(cur->next != NULL){
                temp -> next = cur->next;
                cur->next = temp;
            }
            else{
                printf("Element not found");
            }
        }
    }
}

void delete_specific(int s){
    struct node* temp ,*cur ;
    if(start == NULL){
        printf("List is empty");
    }
    else{
        if(start->data == s){
            temp = start;
            start = temp->next ;
            free(temp);
            temp = NULL;
        }
        else{
            cur = start;
            while(cur->next != NULL && cur->next->data != s){
                cur = cur->next;
            }
            if(cur->next != NULL){
                temp = cur->next;
                cur->next = temp->next;
                free(temp);
                temp = NULL;
            }
            else{
                printf("Not found");
            }
        }
    }
}

void reverse(){
    struct node* temp ,*rev;
    rev = NULL;
    while(start!=NULL){
        temp = start;
        start = temp->next;
        temp->next = rev;
        rev = temp;
    }
    start = rev;
}

void fun_print(struct node*cur){
    if(cur->next != NULL){
        fun_print(cur->next);
    }
    printf("%d",cur->data);
}
void travel_back(){
    if(start==NULL){
        printf("List is empty");
    }else{
        fun_print(start);
    }
}

int main(){
    insert_beg(10);
    insert_end(20);
    insert_end(30);
    insert_after(50,20);
    
    struct node *p = start;
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}
