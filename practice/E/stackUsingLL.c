#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int data;
    struct Stack * next;
} Stack;
Stack * top = NULL;
Stack * create(int data){
    Stack * n = (Stack *)malloc(sizeof(Stack));
    n->data = data;
    n->next = NULL;
    return n;
}

int isEmpty(Stack * sp){
    return sp == NULL;
}

void traverse(Stack * sp){
    if(isEmpty(sp)){
        printf("Stack Underflow!!");
    }else{
        Stack * temp = sp;
        while(temp!= NULL){
            printf("Data: %d\n",temp->data);
            temp = temp->next;
        }
    }
}

void push(Stack ** top, int data){
        Stack * sp = create(data);
        sp->next = *top;
        *top = sp;
}

int main(){
    push(&top,12);
    push(&top,13);
    push(&top,14);
    push(&top,15);
    traverse(top);
}