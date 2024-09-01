#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int * arr;
};

/*
    This function will be used to traverse the stack in reverse order or how the stack looks, here we are storing
    the top value in the ptr so that the original value does not get updated when looping for stack, which I eventually
    did in my try! so it is a point worthy to be noted!!
*/
void traverseStack(struct stack * ptr){
    int i = ptr->top;
    while(i>=0){
        printf("Element : %d\n", ptr->arr[i]);
        i--;
    }
}
/*
    This function is responsible to check whether the stack is empty or not.
    It performs a basic check if the top value is == -1, then it return 1 i.e. true else false
*/
int isEmpty(struct stack * ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}
/*
    This function is resposible to check whether the stack is full or not.
    It performs a check that if the top value is equal to the size-1 than the stack is overflow
*/
int isFull(struct stack * ptr){
    if(ptr->top == ptr->size -1){
        return 1;
    }
    return 0;
}

/*
    This function is reposible to add or insert elements in stack which in general we call pushing elements in stack.
    It first checks whether the stack is overflowed or not else it performs insertion by,
    increment the value of top pointer in stack and inserting the value at the top.
*/
void push(struct stack * ptr, int value){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d in stack\n",value);
    }else{
        ptr->top = ptr->top+1;
        ptr->arr[ptr->top] = value;
    }
}
/*
    This function is responsible for removing the elements from the stack or we can say popping it out of stack.
    It first checks whether the stack is empty or not, if not it then,
    stores the value of the top in a variable as it should be return and then decrements the top value by 1. 
*/
int pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop element\n");
        return  -1;
    }else{
        int send = ptr->arr[ptr->top];
        ptr->top = ptr->top-1;
        return send;
    }
}
/*
    This function is responsible for peek operation. i.e. returning the top element or the last inserted element
*/
int peek(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot Peek");
    }else{
        return ptr->arr[ptr->top];
    }
}

// Same same but different 
int stackTop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot get Top");
    }else{
        return ptr->arr[ptr->top];
    }
}

int stackBottom(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow! Cannot get bottom");
        return -1;
    }else{
        return ptr->arr[0];
    }
}
int main(){
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size * sizeof(int));

    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 3;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    push(s, 6);
    push(s, 12);
    push(s, 16); // last element inserted in stack
    // push(s, 26); // will not get inserted
    traverseStack(s);

    printf("%d\n",peek(s));
    return 0;
}