#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack{
    int size;
    int top;
    char * arr;
};

int isEmpty(struct Stack * ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

int isFull(struct Stack * ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    return 0;
}

void push(struct Stack * ptr, char data){
    if(isFull(ptr)){
        printf("StackOverflow! Cannot insert %d\n",data);
    }else{
        ptr->top = ptr->top + 1;
        ptr->arr[ptr->top] = data;
    }
}

char pop(struct Stack *ptr){
    if(isEmpty(ptr)){
        printf("StackUnderFlow! Cannot pop element\n");
        return -1;
    }else{
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}


char stackTop(struct Stack * ptr){
        return ptr->arr[ptr->top];
}

int precedence(char ch){
    if(ch == '*' || ch == '/'){
        return 3;
    }else if(ch == '+' || ch == '-'){
        return 2;
    }
    return 0;
}
int isOperator(char ch){
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/'){
        return 1;
    }else 
        return 0;
}

char * infixtoPostfix(char * infix){
    struct Stack * sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = strlen(infix);
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char * postfix = (char *)malloc(strlen(infix) * sizeof(char));
    int i = 0;// Track infix traversal
    int j = 0; // Track postfix addition

    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i]; // if jo character h woh operator nahi then it will added to postfix
            i++;
            j++;
        }else{
            if(precedence(infix[i]) > precedence(stackTop(sp))){
                push(sp,infix[i]);
                i++;
            }else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0'; 
    return postfix;
}
int main(){
    char * infix = "+a+b-c/d*l";

    printf("Postfix is %s\n", infixtoPostfix(infix));
    return 0;
}