#include<stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node *start = NULL;

// Doubly LL
void insert_beg(int n){
    struct node*temp;
    temp = malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    temp->prev = NULL;
    
    if(start==NULL){
        start = temp;
    }
    else{
        temp->next = start;
        start -> prev = temp; 
        start = temp ; // here we are moving our pointer from start to the temp which is our first node now 
    }
}

// Doubly insert end
void insert_end(int n){
    struct node*temp;
    temp = malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    temp->prev = NULL;
    
    struct node* cur = start;
    if(start==NULL){
        start = temp;
    }else{
        cur = start;
        while(cur->next != NULL){
            cur = cur->next;
            temp ->prev = cur;
        }
        cur->next = temp;
    }
}


// doubly insert before
void insert_before(int n , int s){
    struct node*temp , *cur;
    if(start == NULL){
        printf("empty");
    }else{
        temp = malloc(sizeof(struct node));
        temp->data = n;
        temp->next = NULL;
        temp->prev = NULL;
        
        cur = start;
        if(start -> data = s){
            temp->next = start;
            start->prev = temp;
            start = temp;
        }else{
            while(cur != NULL && cur ->data){
                cur = cur->next ;
            }
            if(cur != NULL){
                temp->prev = cur->prev;
                temp->next = cur ;
                cur->prev->next =temp;
                cur->prev = temp;
            }
            else{
                printf("Element not found");
            }
        }
    }
}

// doubly insert after;
void insert_after(int n, int s){
    struct node*temp, *cur;
    
    if(start==NULL){
        printf("Empty");
    }else{
        temp = malloc(sizeof(struct node));
        temp->data = n;
        temp->next = NULL;
        temp->prev = NULL;
        cur = start;
        while(cur!= NULL && cur->data != s){
            cur = cur->next;
        }
        if(cur!= NULL){
            temp->next = cur->next;
            temp->prev =cur;
            if(cur->next != NULL){
                cur->next->prev = temp;
            }
            cur->next = temp;
        }else{
            printf("404");
        }
    }
}
   
    
 // for doubly delete first
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

// check once
// delete specific
void delete_specific(int n){
    struct node* cur;
    if(start == NULL){
        printf("Empty");
    }else{
        cur = start;
        if(start->data == n){
            start = start->next;
            if(start != NULL){
                start->prev = NULL;
                free(cur);
                cur = NULL;
                else{
                    while(cur!= NULL && cur->data != n){
                        
                    }
                }
            }
        }
    }
}

// same as single LL
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



int main()
{
    // switch for user input
    insert_beg(10);
    insert_end(20);
    insert_end(30);
    
    delete_first();

    return 0;
}
