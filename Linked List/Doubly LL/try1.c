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

// check
/*
void insert_after(int n , int s){
    struct node* temp,*cur;
    temp = malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    if(start == NULL){
        start = temp;
    }else{
        cur = start;
        while(cur != start && cur->data != s){
            temp->next = cur->next;
            cur->next = temp;
        }
    }else{
        printf("Element not found");
    }
}
*/

void insert_before(int n ,int s){
    struct node* temp,*cur;
    if(start == NULL){
        printf("List is empty");
    }else{
        if(start==NULL){
            printf("List is empty");
        }
        else{
            temp = malloc(sizeof(struct node));
            temp->data = n;
            temp->next = NULL;
            if(start->data == s){
                temp->next = start;
                start = temp;
            }else{
                cur = start;
                while(cur->next!= NULL && cur->data!= s){
                    cur = cur->next;
                }
                if(cur->next != NULL){
                    temp->next = cur->next;
                    cur->next = temp;
                }else{
                    printf("Element not found");
                }
            }
        }
    }
}
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

int delete_last(){
    int x = -1;
    struct node*temp,*cur;
    if(start == NULL){
        printf("List is empty");
    }else{
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
            x = temp->data;
            cur->next = NULL;
            free(temp);
            temp = NULL;
        }
    }
    return x;
}

int delete_specific(int s){
    struct node* temp,*cur;
    if(start==NULL){
        printf("list is empty");
    }
    else{
        if(start->data == s){
            temp = start;
            start = temp->next;
            free(temp);
            temp = NULL;
        }else{
            cur = start;
            while(cur->next != NULL && cur->next->data !=s){
                cur=cur->next;
            }
            if(cur->next != NULL){
                temp = cur->next;
                cur->next = temp->next;
                free(temp);
                temp = NULL;
            }else{
                printf("Element not found");
            }
        }
        
    }
}

void reverse(){
    struct node* temp,*rev;
    rev = NULL;
    
    while(start!=NULL){
        temp = start;
        start = temp->next;
        temp ->next = rev;
        rev = temp;
    }
    start = rev;
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
