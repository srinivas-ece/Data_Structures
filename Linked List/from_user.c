#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *start = NULL;

void insert_beg(int n){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = n;
    temp->next = start;
    start = temp;
}

void insert_end(int n){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;

    if(start == NULL){
        start = temp;
    } else {
        struct node* cur = start;
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = temp;
    }
}

void insert_after(int n, int s){
    if(start == NULL){
        printf("List empty\n");
        return;
    }
    struct node* cur = start;
    while(cur != NULL && cur->data != s){
        cur = cur->next;
    }
    if(cur != NULL){
        struct node* temp = malloc(sizeof(struct node));
        temp->data = n;
        temp->next = cur->next;
        cur->next = temp;
    } else {
        printf("Element not found\n");
    }
}

int delete_first(){
    if(start == NULL){
        printf("List empty\n");
        return -1;
    }
    struct node* temp = start;
    int x = temp->data;
    start = start->next;
    free(temp);
    return x;
}

int delete_last(){
    if(start == NULL){
        printf("List empty\n");
        return -1;
    }
    int x;
    if(start->next == NULL){
        x = start->data;
        free(start);
        start = NULL;
        return x;
    }
    struct node *cur = start;
    while(cur->next->next != NULL){
        cur = cur->next;
    }
    struct node* temp = cur->next;
    x = temp->data;
    cur->next = NULL;
    free(temp);
    return x;
}

void delete_specific(int s){
    if(start == NULL){
        printf("List empty\n");
        return;
    }
    struct node* temp;
    if(start->data == s){
        temp = start;
        start = start->next;
        free(temp);
        return;
    }
    struct node* cur = start;
    while(cur->next != NULL && cur->next->data != s){
        cur = cur->next;
    }
    if(cur->next != NULL){
        temp = cur->next;
        cur->next = temp->next;
        free(temp);
    } else {
        printf("Element not found\n");
    }
}

void reverse(){
    struct node* temp ,*rev=NULL;
    while(start!=NULL){
        temp = start;
        start = temp->next;
        temp->next = rev;
        rev = temp;
    }
    start = rev;
}

void display(){
    struct node* p = start;
    if(!p){
        printf("List empty\n");
        return;
    }
    printf("List: ");
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    int choice, val, after;
    while(1){
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after element\n");
        printf("4. Delete first\n");
        printf("5. Delete last\n");
        printf("6. Delete specific element\n");
        printf("7. Reverse list\n");
        printf("8. Display list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d",&val);
                insert_beg(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d",&val);
                insert_end(val);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d",&val);
                printf("Insert after which element? ");
                scanf("%d",&after);
                insert_after(val,after);
                break;
            case 4:
                val = delete_first();
                if(val!=-1) printf("Deleted: %d\n",val);
                break;
            case 5:
                val = delete_last();
                if(val!=-1) printf("Deleted: %d\n",val);
                break;
            case 6:
                printf("Enter element to delete: ");
                scanf("%d",&val);
                delete_specific(val);
                break;
            case 7:
                reverse();
                printf("List reversed.\n");
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
