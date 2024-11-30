#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int front;
    int rear;
    int size;
    int * arr;
} Queue;

int isEmpty(Queue * q){
    if(q->front == -1 || q->front > q->rear){
        return 1;
    }
    return 0;
}

int isFull(Queue * q){
    if(q->rear == q->size-1){
        return 1;
    }
    return 0;
}

void enqueue(Queue * q, int data){
    if(isFull(q)){
        printf("Queue Overflow!!\n");
    }
    else{
        if(q->front == -1){
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = data;
    }
}

int dequeue(Queue * q){
    if(isEmpty(q)){
        printf("Queue Underflow!!\n");
        return -1;
    }else{
        int res = q->arr[q->front];
        q->front++; 
        return res;
    }
}

void traverse(Queue * q){
    for(int i = q->front; i <= q->rear; i++){
        printf("Data: %d\n",q->arr[i]);
    }
}

int main(){
    Queue * q = (Queue *)malloc(sizeof(Queue));
    q->size = 7;
    q->rear = q->front = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    enqueue(q,12);
    enqueue(q,16);
    enqueue(q,71);
    traverse(q);
    printf("After Deletion\n");
    dequeue(q);
    traverse(q);
}