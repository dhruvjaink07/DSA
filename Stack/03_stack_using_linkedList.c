#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

int isEmpty(struct Node * top){
    if(top==NULL){
        return 1;
    }
    return 0;
}

int isFull(struct Node * top){
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }else{
        return 0;
    }
}   

struct Node * push(struct Node * top, int data){
    if(isFull(top)){ // Theoritically we cannot limit linkedlist but if the memory is exhausted then the new node will not be created and will return NULL
    printf("Stack OverFlow! cannot push %d\n",data);
    }else{
        struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = top;
        top = ptr;
        return top;
    }
}

int pop(struct Node ** top){ // It is pointer to pointer which means changes done here will be getting reflected in the actual top Node without returning it
    if(isEmpty(*top)){
        printf("Stack Underflow\n");
        return -1;
    }else{
    struct Node * ptr = *top;
    *top = (*top) -> next;
    int val = ptr->data;
    free(ptr);
    return val;
    }
}
void traverse(struct Node * ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow!\n");
    }else{
        while(ptr!=NULL){
        printf("Element : %d\n", ptr->data);
        ptr = ptr -> next;
    }
    }
}

int main(){ 
    struct Node * top = NULL;

    // top = (struct Node *)malloc(sizeof(struct Node));

    printf("Stack before push\n");
    traverse(top);
    top = push(top, 26);
    top = push(top,32);
    printf("Stack after push\n");
    traverse(top);
    printf("Stack after pop\n");
    int x = pop(&top); // here we are not changing the value of top so inorder to make it change we will go by passing the address of top pointer 
    printf("Value popped from stack is %d\n",x);
    traverse(top);
    return 0;
}