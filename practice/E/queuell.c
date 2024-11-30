#include <stdio.h>
#include <malloc.h>

typedef struct Node{
    int data;
    struct Node * next;
} Node;

Node * front = NULL;
Node * rear = NULL;

Node * createNode(int data){
    Node * n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL; 
    return n;
}

void traversal(Node * q){
    while(q != NULL){
        printf("Data: %d\n",q->data);
        q = q->next;
    } 
}

void enqueue(int data){
    Node * n = createNode(data);
    if(front == NULL){
        front = rear = n;
    }else{
        rear -> next = n;
        rear = n;
    }
}

int dequeue(){
    int res = -1;
    Node * ptr = front;
    if(front == NULL){
        printf("Queue Underflow!!\n");
        return res;
    }else{
        res = front->data;
        front = front->next;
        free(ptr);
        return res;
    }
}

int main(){
    printf("Enqueing Elements: \n");
    enqueue(49);
    enqueue(50);
    enqueue(51);
    traversal(front);
    dequeue();
    printf("Dequeing Elements: \n");
    traversal(front);
}