// Here is the basic function for 
// isempty()
// isfull()
// push()
// pop()
// peek()

// IMP always write the function braces() otherwise it won't worl properly
#include <stdio.h>
#include <stdlib.h>   

struct stack {
    int tos;
    int size;
    int *s;
};

struct stack sta;

// isfull()
int isfull() { 
    if(sta.tos == sta.size-1) 
        return 1;
    else 
        return 0; 
    } 


// isempty()
int isempty() { 
    if(sta.tos == -1) 
        return 1;
    else 
        return 0; 
    
    }

// push()
void push(int n) {
    if (isfull()) {
        printf("Stack is full\n");
    } else {
        sta.tos++;
        sta.s[sta.tos] = n;
        printf("%d pushed to stack\n", n);
    }
}

// pop()
int pop() {
    if (isempty()) {                      
        printf("Stack is empty, can't pop\n");
        return -1;                         
    } else {
        int popped_item = sta.s[sta.tos];
        sta.tos--;
        return popped_item;
    }
}


// peek()
int peek() {
    if (isempty()) {
        printf("Stack is empty\n");
        return -1;                        
    } else {
        return sta.s[sta.tos];
    }
}

int main() {
    sta.tos = -1; // here the top of the stack is -1 because we are working on arays
    sta.size = 0;
    sta.s = NULL;

    printf("Enter the size = ");
    scanf("%d", &sta.size);

    sta.s = (int*)malloc(sizeof(int) * sta.size);
    if (sta.s == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    push(10);
    push(20);

    printf("Top element: %d\n", peek());
    printf("Popped: %d\n", pop());
    printf("Top element after pop: %d\n", peek());

    return 0;
}



 






// User chooses the operation here 
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int tos;
    int size ;
    int* s ;    
};

struct stack sta;

int isfull(){
    if(sta.tos == sta.size-1)
        return 1;
    else
        return 0;
}

int isempty(){
    if(sta.tos == -1)
        return 1;
    else
        return 0;
}

void push(int n){
    if(isfull()){
        printf("Stack is full\n");
    }else{
        sta.tos++;
        sta.s[sta.tos] = n;
        printf("%d is pushed into the stack\n",n);
    }
}

int pop(){
    if(isempty()){
        printf("The stack is empty\n");
        return -1;
    }else{
        int popitem = sta.s[sta.tos];
        sta.tos--;
        return popitem;
    }
}

int peek(){
    if(isempty()){
        printf("The stack is empty\n");
        return -1;
    }else{
        return sta.s[sta.tos];
    }
}

int main()
{
    sta.tos = -1;
    sta.size = 0;
    sta.s = NULL;
    int i;
    int op;
    int push1;  // <-- moved here so case 3 can use it

    printf("Enter the size : ");
    scanf("%d",&sta.size);

    sta.s = (int*)malloc(sizeof(int)*sta.size);
    if(sta.s == NULL){
        printf("Memory allocation failed");
        return 1;
    }

    while(1){
        printf("\nEnter the operation\n");
        printf("1.isfull\n 2.isempty\n 3.push\n 4.pop\n 5.peek\n 6.exit\n");
        scanf("%d",&op);

        switch(op){
            case 1 : 
                if(isfull()) {
                    printf("stack is full\n");
                } else {
                    printf("stack is not full\n");
                }
                break;

            case 2 : 
                if (isempty()) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;   // <-- added break here

            case 3 :
                printf("Enter the value you want to push: ");
                scanf("%d",&push1);
                push(push1);
                break;

            case 4 : 
                printf("popped element %d\n",pop());
                break;

            case 5 : 
                printf("top element %d\n",peek());
                break;
            case 6:
                exit(0);
                break;

            default : 
                printf("Enter a valid operation\n");
                break;
        }
    }
    return 0;
}













// Balancing of paranthesis

#include <stdio.h>
#include <stdlib.h>   // for malloc
#include <string.h>   // for strlen

struct stack {
    int tos;
    int size;
    int *s;
};

struct stack sta;

int isfull() { 
    if(sta.tos == sta.size-1) 
        return 1;
    else 
        return 0; 
} 
    
int isempty() { 
    if(sta.tos == -1) 
        return 1;
    else 
        return 0; 
}

void push(int n) {
    if (isfull()) {
        printf("Stack is full\n");
    } else {
        sta.tos++;
        sta.s[sta.tos] = n;
        //printf("%d pushed to stack\n", n);
    }
}

int pop() {
    if (isempty()) {                      
        printf("Stack is empty, can't pop\n");
        return -1;                         
    } else {
        int popped_item = sta.s[sta.tos];
        sta.tos--;
        return popped_item;
    }
}

int peek() {
    if (isempty()) {
        printf("Stack is empty\n");
        return -1;                        
    } else {
        return sta.s[sta.tos];
    }
}

int main() {
    sta.tos = -1;
    sta.size = 0;
    sta.s = NULL;

    printf("Enter the size = ");
    scanf("%d", &sta.size);

    sta.s = (int*)malloc(sizeof(int) * sta.size);
    if (sta.s == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    char a[100];
    printf("Enter a string: ");
    scanf("%s", a);  // just a (not a[i])

    int flag = 0;
    for(int i=0 ; i<strlen(a) ; i++){
        char ch = a[i];
        switch(ch){
            case '(':
            case '[':
            case '{':
                push(ch);
                break;

            case ')': 
                if(!isempty() && peek()=='('){
                    pop();
                } else {
                    flag = 1;
                }
                break;

            case ']':
                if(!isempty() && peek()=='['){
                    pop();
                } else {
                    flag = 1;
                }
                break;

            case '}':
                if(!isempty() && peek()=='{'){
                    pop();
                } else {
                    flag = 1;
                }
                break;

            default : break;
        }
        if(flag==1) break;
    }

    if(flag==1){
        printf("not balanced\n");
    } else if(isempty()){
        printf("balanced\n");
    } else {
        printf("unbalanced\n");
    }

    free(sta.s);
    return 0;
}














// infix to postfix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // <-- added

struct stack {
    int tos;
    int size;
    int* s;    
};

struct stack sta;

int isfull() {
    return (sta.tos == sta.size - 1);
}

int isempty() {
    return (sta.tos == -1);
}

void push(int n) {
    if (isfull()) {
        printf("Stack is full\n");
    } else {
        sta.tos++;
        sta.s[sta.tos] = n;
    }
}

int pop() {
    if (isempty()) {
        printf("The stack is empty\n");
        return -1;
    } else {
        int popitem = sta.s[sta.tos];
        sta.tos--;
        return popitem;
    }
}

int peek() {
    if (isempty()) {
        return -1;
    } else {
        return sta.s[sta.tos];
    }
}

int prec(char c) {
    switch (c) {
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        case '(':
        case '[':
        case '{': return 0;
        default: return -1;    // <-- added
    }
}

int main() {
    sta.tos = -1;
    sta.size = 0;
    sta.s = NULL;
    int op;
    int push1; 
    int j = 0;

    char input[100];
    char output[100];

    printf("Enter the size : ");
    scanf("%d", &sta.size);

    sta.s = (int*)malloc(sizeof(int) * sta.size);
    if (sta.s == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    printf("Enter the expression: ");
    scanf("%s", input);  // <-- removed &

    for (int i = 0; i < (int)strlen(input); i++) {
        char ch = input[i];

        switch (ch) {
            case '(':
            case '[':
            case '{':
                push(ch);
                break;

            case ')':
                while (!isempty() && peek() != '(') {
                    output[j++] = pop();
                }
                if (!isempty()) pop(); // pop '('
                break;

            case ']':
                while (!isempty() && peek() != '[') {
                    output[j++] = pop();
                }
                if (!isempty()) pop();
                break;

            case '}':
                while (!isempty() && peek() != '{') {
                    output[j++] = pop();
                }
                if (!isempty()) pop();
                break;

            case '*':
            case '/':
            case '+':
            case '-':
                while (!isempty() && prec(peek()) >= prec(ch)) {  
                    output[j++] = pop();
                }
                push(ch);
                break;

            default:
                output[j++] = ch;
                break;
        }
    }
    while (!isempty()) {
        output[j++] = pop();
    }
    output[j] = '\0';    // <-- terminate string
    printf("Postfix expression: %s\n", output);

    return 0;
}










// Simpler Way for infix to postfix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // <-- added

struct stack {
    int tos;
    int size;
    int* s;    
};

struct stack sta;

int isfull() {
    return (sta.tos == sta.size - 1);
}

int isempty() {
    return (sta.tos == -1);
}

void push(int n) {
    if (isfull()) {
        printf("Stack is full\n");
    } else {
        sta.tos++;
        sta.s[sta.tos] = n;
    }
}

int pop() {
    if (isempty()) {
        printf("The stack is empty\n");
        return -1;
    } else {
        int popitem = sta.s[sta.tos];
        sta.tos--;
        return popitem;
    }
}

int peek() {
    if (isempty()) {
        return -1;
    } else {
        return sta.s[sta.tos];
    }
}

int prec(char c) {
    switch (c) {
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        case '(':
        case '[':
        case '{': return 0;
        default: return -1;    // <-- added
    }
}

int main() {
    sta.tos = -1;
    sta.size = 0;
    sta.s = NULL;
    int op;
    int push1; 
    int j = 0;

    char input[100];
    char output[100];

    printf("Enter the size : ");
    scanf("%d", &sta.size);

    sta.s = (int*)malloc(sizeof(int) * sta.size);
    if (sta.s == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    printf("Enter the expression: ");
    scanf("%s", input);  

    for (int i = 0; i < (int)strlen(input); i++) {
        char ch = input[i];

        switch (ch) {
        case '(':
        case '[':
        case '{': push(ch);
        break;

        case ')':
            // pop until '('
            while (!isempty()) {
            char top = peek();
            if (top == '(') {
                pop();  // remove '(' and stop
                break;
            }
            output[j++] = pop();   // pop operators into output
        }
        break;

        case ']':
            // pop until '['
            while (!isempty()) {
            char top = peek();
            if (top == '[') {
                pop();  // remove '[' and stop
                break;
            }
            output[j++] = pop();   // pop operators into output
        }
        break;

        case '}':
            // pop until '{'
            while (!isempty()) {
            char top = peek();
            if (top == '{') {
                pop();  // remove '{' and stop
                break;
            }
            output[j++] = pop();   // pop operators into output
        }
        break;

        case '*':
        case '/':
        case '+':
        case '-':
        // pop all operators from stack that have higher or equal precedence
        while (!isempty()) {
                char top = peek();
            if (prec(top) < prec(ch)) {
                break;  // top operator has lower precedence, stop popping
            }
            output[j++] = pop();  // pop higher/equal precedence operator into output
            }
            push(ch);  // push the current operator onto the stack
            break;

        default:
            output[j++] = ch;  // operand goes directly to output
            break;

        
    }// switch
    
}//for

    while (!isempty()) {
        output[j++] = pop();
    }
    output[j] = '\0';    // <-- terminate string
    printf("Postfix expression: %s\n", output);

    return 0;
}//main












// Simpler Way for infix to prefix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
  int tos;
  int size;
  int*s;
};

struct stack sta;
int isfull(){
    if(sta.tos == sta.size-1)
        return 1;
    else
        return 0;
}

int isempty(){
    if(sta.tos == -1)
        return 1;
    else
        return 0;
}

void push(int n){
    if(isfull()){
        printf("Stack is full");
    }else{
        sta.tos++;
        sta.s[sta.tos] = n;
        printf("%d is pushed into the stack\n",n);
    }
}

int pop(){
    if(isempty()){
        printf("The stack is empty");
        
    }else{
        int popitem = sta.s[sta.tos];
        sta.tos--;
        return popitem;
    }    
}

int peek(){
    if(isempty()){
        printf("The stack is empty");
        return -1;
    }else{
        int popitem = sta.s[sta.tos];
        return popitem;
    }
}

void display(){
    if(sta.tos == -1){
        printf("Stack is empty");
    }
    else{
        for(int i=sta.tos ; i>=0 ; i--){
            printf("%d\t",sta.s[i]);
        }
    }
}

void reverse(char a[]){
    
    int len = strlen(a); 
    for(int i = 0 ; i<len/2 ; i++){
        int temp = a[i];
        a[i] = a[len-1-i];
        a[len-1-i] = temp;
    }
}

int prec(char c) {
    switch (c) {
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        case '(':
        case '[':
        case '{': return 0;
        default: return -1;    // <-- added
    }
}

int main(){
    sta.tos = -1;
    sta.size = 0;
    sta.s = NULL;
    char input[100];
    char output[100];
    int j = 0 ;
    
    printf("Enter the size = ");
    scanf("%d",&sta.size);
    
    sta.s = (int*)malloc(sizeof(int)*sta.size);
    
    if(sta.s == NULL){
        printf("Memoryallocation failed");
        return 1;
    }
    
    printf("Enter the string ");
    scanf("%s",input);
    
    reverse(input);
    printf("the reverse string is %s",input);
    for (int i = 0; i < strlen(input); i++) {
        char ch = input[i];

        switch (ch) {
        case ')':
        case ']':
        case '}': push(ch);
        break;

        case '(':
            // pop until '('
            while (!isempty()) {
            char top = peek();
            if (top == ')') {
                pop();  // remove '(' and stop
                break;
            }
            output[j++] = pop();   // pop operators into output
        }
        break;

        case '[':
            // pop until '['
            while (!isempty()) {
            char top = peek();
            if (top == ']') {
                pop();  // remove '[' and stop
                break;
            }
            output[j++] = pop();   // pop operators into output
        }
        break;

        case '{':
            // pop until '{'
            while (!isempty()) {
            char top = peek();
            if (top == '}') {
                pop();  // remove '{' and stop
                break;
            }
            output[j++] = pop();   // pop operators into output
        }
        break;

        case '*':
        case '/':
        case '+':
        case '-':
        // pop all operators from stack that have higher or equal precedence
        while (!isempty()) {
                char top = peek();
            if (prec(top) < prec(ch)) {
                break;  // top operator has lower precedence, stop popping
            }
            output[j++] = pop();  // pop higher/equal precedence operator into output
            }
            push(ch);  // push the current operator onto the stack
            break;

        default:
            output[j++] = ch;  // operand goes directly to output
            break;

        
    }// switch
    
}//for

    while (!isempty()) {
        output[j++] = pop();
    }
    output[j] = '\0';// <-- terminate string
    
    reverse(output);
    printf("Postfix expression: %s\n", output);

    return 0;
    
}















#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
  int tos;
  int size;
  int*s;
};

struct stack sta;
int isfull(){
    if(sta.tos == sta.size-1)
        return 1;
    else
        return 0;
}

int isempty(){
    if(sta.tos == -1)
        return 1;
    else
        return 0;
}

void push(int n){
    if(isfull()){
        printf("Stack is full");
    }else{
        sta.tos++;
        sta.s[sta.tos] = n;
        printf("%d is pushed into the stack\n",n);
    }
}

int pop(){
    if(isempty()){
        printf("The stack is empty");
        
    }else{
        int popitem = sta.s[sta.tos];
        sta.tos--;
        return popitem;
    }    
}

int peek(){
    if(isempty()){
        printf("The stack is empty");
        return -1;
    }else{
        int popitem = sta.s[sta.tos];
        return popitem;
    }
}

void display(){
    if(sta.tos == -1){
        printf("Stack is empty");
    }
    else{
        for(int i=sta.tos ; i>=0 ; i--){
            printf("%d\t",sta.s[i]);
        }
    }
}

void reverse(char a[]){
    
    int len = strlen(a); 
    for(int i = 0 ; i<len/2 ; i++){
        int temp = a[i];
        a[i] = a[len-1-i];
        a[len-1-i] = temp;
    }
}

int prec(char c) {
    switch (c) {
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        case '(':
        case '[':
        case '{': return 0;
        default: return -1;    // <-- added
    }
}

int main(){
    sta.tos = -1;
    sta.size = 0;
    sta.s = NULL;
    char input[100];
    char output[100];
    int j = 0 ;
    
    printf("Enter the size = ");
    scanf("%d",&sta.size);
    
    sta.s = (int*)malloc(sizeof(int)*sta.size);
    
    if(sta.s == NULL){
        printf("Memoryallocation failed");
        return 1;
    }
    
    printf("Enter the string ");
    scanf("%s",input);
    
    reverse(input);
    printf("the reverse string is %s",input);
    
    for (int i = 0; i < strlen(input); i++) {
        char ch = input[i];
        
        
        switch (ch) {
        case ')':
        case ']':
        case '}': push(ch);
        break;

        case '(':
            // pop until '('
            while (!isempty()) {
            char top = peek();
            if (top == ')') {
                pop();  // remove '(' and stop
                break;
            }
            output[j++] = pop();   // pop operators into output
        }
        break;

        case '[':
            // pop until '['
            while (!isempty()) {
            char top = peek();
            if (top == ']') {
                pop();  // remove '[' and stop
                break;
            }
            output[j++] = pop();   // pop operators into output
        }
        break;

        case '{':
            // pop until '{'
            while (!isempty()) {
            char top = peek();
            if (top == '}') {
                pop();  // remove '{' and stop
                break;
            }
            output[j++] = pop();   // pop operators into output
        }
        break;

        case '*':
        case '/':
        case '+':
        case '-':
        // pop all operators from stack that have higher or equal precedence
        while (!isempty()) {
                char top = peek();
            if (prec(top) < prec(ch)) {
                break;  // top operator has lower precedence, stop popping
            }
            output[j++] = pop();  // pop higher/equal precedence operator into output
            }
            push(ch);  // push the current operator onto the stack
            break;

        default:
            output[j++] = ch;  // operand goes directly to output
            break;

        
    }// switch
    
}//for

    while (!isempty()) {
        output[j++] = pop();
    }
    output[j] = '\0';// <-- terminate string
    
    reverse(output);
    printf("Postfix expression: %s\n", output);
    
    int a,b,c;
    for(int i=0 ; i<strlen(output); i++){
        char ch =output[i];
        switch(ch){
            case '+': a = pop();
                    b = pop();
                    c = b+a;
                    push(c);
                    break;
            case '-': a = pop();
                    b = pop();
                    c = b-a;
                    push(c);
                    break;
            case '*': a = pop();
                    b = pop();
                    c = b*a;
                    push(c);
                    break;
            case '/': a = pop();
                    b = pop();
                    c = b/a;
                    push(c);
                    break;
            
            default : push(atoi(&ch));
                    break;
        }
    }
    printf("evaluation %d",pop());
    return 0;
    
}
