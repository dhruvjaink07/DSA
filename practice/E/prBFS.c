#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int size;
    int r;
    int f;
    int * arr;
} Queue;

int isEmpty(Queue * q){
    if(q->f == q->r){
        return 1;
    }
    return 0;
}

int isFull(Queue * q){
    if(q->r == q->size -1){
        return 1;
    }
    return 0;
}

void enqueue(Queue * q, int data){
    if(isFull(q)){
        printf("Queue Overflow!!");
    }else{
        q->r ++;
        q->arr[q->r] = data;
    }
}

int dequeue(Queue * q){
    int res = -1;
    if(isEmpty(q)){
        printf("Queue Underflow!!");
        return res;
    }
    else{
    q->f++;
    res = q->arr[q->f];
    return res;
    }
}

int main(){
    Queue q;
    q.size = 40;
    q.r = q.f = 0;
    q.arr = (int *)malloc(sizeof(int) * q.size);

    // BFS
    int node;
    int i = 3;
    int visited[7] = {0,0,0,0,0,0,0};

    int a[7][7] = {
        {0,1,1,1,0,0,0},    // Connections for node 0
        {1,0,1,0,0,0,0},    // Connections for node 1
        {1,1,0,1,1,0,0},    // Connections for node 2
        {1,0,1,0,1,0,0},    // Connections for node 3
        {0,0,1,1,0,1,1},    // Connections for node 4
        {0,0,0,0,1,0,0},    // Connections for node 5
        {0,0,0,0,1,0,0}     // Connections for node 6
    };

    printf("%d",i);
    visited[i] = 1; // Make starting node as visited

    enqueue(&q,i); // Also enqueue the visited node in the exploration queue
    while(!isEmpty(&q)){
        int node = dequeue(&q);

        for(int j = 0; j < 7; j++){
            if(a[node][j] == 1 && visited[j] == 0){
                printf("%d",j);
                visited[j] = 1;
                enqueue(&q,j);
            }
        }
    }

    return 0;
}