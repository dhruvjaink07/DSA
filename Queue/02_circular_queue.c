#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int rear;
    int front;
    int * arr;
};

int isEmpty(struct Queue * q){
    if(q->rear == q->front){
        return 1;
    }
    return 0;
}

int isFull(struct Queue * q){
    if((q->rear+1)%q->size == q->front){
        return 1;
    }
    return 0;
}

void enqueue(struct Queue * q, int data){
    if(isFull(q)){
        printf("Queue Overflow! %d will not be enqueued\n",data);
        return;
    }else{
        q->rear = (q->rear+1)%q->size;
        q->arr[q->rear] = data;
        printf("Enqueued Element %d\n",data);
    }
}

int dequeue(struct Queue * q){
    int val = -1;
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return val;
    }else{
        q->front = (q->front+1) % q->size;
        val = q->arr[q->front];
    }
    return val;
}


int main(){
    struct Queue q;
    q.size = 4;
    q.rear = q.front = 0; // Difference from Normal Queue
    q.arr = (int *)malloc(q.size * sizeof(int));


    // Always we will be able to insert size -1 elements only cause there is one block always empty for purposes of rear and front
    enqueue(&q, 19);
    enqueue(&q,20);
    enqueue(&q, 21);
    
    // printf("The dequeued element is %d\n",dequeue(&q));
    // printf("The dequeued element is %d\n",dequeue(&q));
    // printf("The dequeued element is %d\n",dequeue(&q));
    // printf("The dequeued element is %d\n",dequeue(&qu));

    if(isEmpty(&q)){
        printf("Queue is Empty\n");
    }
    if(isFull(&q)){
        printf("Queue is Full\n");
    }
}