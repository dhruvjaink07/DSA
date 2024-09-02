#include <stdio.h>
#include <stdlib.h>
// Same as previous but using Global Variable
struct Node{
    int data;
    struct Node * next;
};

struct Node * top = NULL;

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

int pop(struct Node * tp){ // It is pointer to pointer which means changes done here will be getting reflected in the actual top Node without returning it
    if(isEmpty(tp)){
        printf("Stack Underflow\n");
        return -1;
    }else{
    struct Node * ptr = tp;
    top = tp -> next;
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
int peek(int pos){
    struct Node * p = top;
    for(int i = 0; (i < pos -1 && p != NULL); i++){
        p = p->next;
    }
    if(p!=NULL){
        return p->data;
    }else{
        return -1;
    }
}


// Performs O(1)
int stackTop(struct Node * top){
    return top->data;
}

// Performs O(n)
int stackBottom(struct Node * top){
    struct Node * ptr = top;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    return ptr->data;
}

int main(){ 
    top = push(top, 26);
    top = push(top,32);
    top = push(top,6);
    traverse(top);
    
    for(int i = 0; i<3; i++){
        printf("Value at position 1 is %d\n",peek(i+1));
    }

    printf("The Top most Element of stack is %d\n",stackTop(top));
    printf("The Bottom most Element of stack is %d\n",stackBottom(top));

    return 0;
}