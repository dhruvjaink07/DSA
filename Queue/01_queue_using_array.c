#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int rearInd;
    int frontInd;
    int * arr;
};

int isEmpty(struct Queue * qu){
    if(qu->rearInd == qu->frontInd){
        return 1;
    }
    return 0;
}

int isFull(struct Queue * qu){
    if(qu->rearInd == qu->size-1){
        return 1;
    }
    return 0;
}

void enqueue(struct Queue * qu, int data){
    if(isFull(qu)){
        printf("Queue Overflow! Cannot insert %d\n",data);
    }else{
        qu->rearInd++;
        qu->arr[qu->rearInd] = data;
    }
}

int dequeue(struct Queue * qu){
    if(isEmpty(qu)){
        printf("Queue Underflow! Cannot remove element\n");
        return -1;
    }else{
        qu->frontInd = qu->frontInd + 1;
        int res = qu->arr[qu->frontInd];
        return res;
    }
}

int main(){
    struct Queue qu;
    qu.size = 100;
    qu.rearInd = -1;
    qu.frontInd = -1;
    qu.arr = (int *)malloc(qu.size * sizeof(int));

    enqueue(&qu, 19);
    enqueue(&qu,20);


    printf("The dequeued element is %d\n",dequeue(&qu));
    printf("The dequeued element is %d\n",dequeue(&qu));
    printf("The dequeued element is %d\n",dequeue(&qu));
    printf("The dequeued element is %d\n",dequeue(&qu));

    enqueue(&qu, 6);
    printf("The dequeued element is %d\n",dequeue(&qu));
    return 0;
}