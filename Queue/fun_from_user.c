#include<stdlib.h>
#include <stdio.h>


struct queue{
  int front;
  int rear;
  int size;
  int *q;
};

struct queue que;

// full
int overflow(){
    if(que.rear == que.size-1)
        return 1;
    else
        return 0;
}

// empty
int underflow(){
    if(que.rear == -1 && que.front == -1)
        return 1;
    else
        return 0;
}

// to add elements from rear
void enque(int n){
    if(overflow()){
        printf("\nQueue is full, cant add\n");
    }else{
        if(que.front == -1){
            que.front++;
        }
        que.rear++;
        que.q[que.rear] = n;
        printf("\n%d is added in the que\n",n);
        }
    }

// to delete elements from front
int deque(){
    int x =-1;
    if(underflow()){
        printf("\nQueue is empty !\n");
    }else{
        x = que.q[que.front];
        if(que.front == que.rear){
            que.front = -1;
            que.rear = -1;
        }else{
            que.front++;
        }
        return x;
    }
}

void display(){
    if(!underflow()){
        printf("Que = ");
        for(int i=que.front ; i<=que.rear ; i++){
            printf("%d\t",que.q[i]);
        }
        printf("\n");
    }else{
        printf("Que is empty\n");
    }
}

int main()
{
    que.front = -1;
    que.rear = -1;
    que.size = 0;
    que.q = NULL;
    int operation;
    int add;
    printf("Enter the size = ");
    scanf("%d",&que.size);
    
    que.q = (int*)malloc(sizeof(int)*que.size);
    if(que.q == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    while(1){
        printf("\nOperations on Queue\n");
        printf("\n1.Enque(add elements)\n");
        printf("\n2.Deque(del elements)\n");
        printf("\n3.Display\n");
        printf("\n4.Exit\n");
        printf("\nEnter the number = ");
        scanf("%d",&operation);
        
        switch(operation){
            case 1 : printf("Enter the value you want to add in Queue = ");
                    scanf("%d",&add);
                    enque(add);
                    break;
            case 2 : deque();
                    break;
            case 3 : display();
                    break;
          case 4: exit(0);
                  break;
            default : printf("Invalid expression");
        }   
    }
    return 0;
}
