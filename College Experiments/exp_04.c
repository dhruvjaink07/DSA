#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int rear;
    int front;
    int * arr;
};

int isEmpty(struct Queue * qu){
    if(qu->rear == qu->front){
        return 1;
    }
    return 0;
}

int isFull(struct Queue * qu){
    if(qu->rear == qu->size-1){
        return 1;
    }
    return 0;
}

void enqueue(struct Queue * qu, int data){
    if(isFull(qu)){
        printf("Queue Overflow! Cannot insert %d\n",data);
    }else{
        qu->rear++;
        qu->arr[qu->rear] = data;
    }
}

int dequeue(struct Queue * qu){
    if(isEmpty(qu)){
        printf("Queue Underflow! Cannot remove element\n");
        return -1;
    }else{
        qu->front = qu->front + 1;
        int res = qu->arr[qu->front];
        return res;
    }
}

void traverse(struct Queue * q){
    if(isEmpty(q)){
        printf("Queue Empty! \n");
        return ;
    }
    printf("Traversing Queue\n");
    for(int i = q->front+1; i <= q->rear; i++){
        printf("%d\t", q->arr[i]);
    }
    printf("\n");
}
int main(){
    int qSize;
    printf("Determine the size of queue: ");
    scanf("%d", &qSize);
    printf("\n");
    struct Queue qu;
    qu.size = qSize;
    qu.rear = -1;
    qu.front = -1;
    qu.arr = (int *)malloc(qu.size * sizeof(int));

    printf("Enter 1 for enqueuing element\n");
    printf("Enter 2 for dequeuing element\n");
    printf("Enter 3 to traverse the Queue\n");
    printf("Enter 0 to quit\n");

    int i = 1;
    while(i){
    int choice;
    printf("Enter your choice:");
    scanf("%d",&choice);
    printf("\n");
    switch(choice){
        case 0:{
            printf("Bye Bye\n");
            exit(0);
            break;
        }
        case 1:{
            int value;
            printf("Enter Value: \n");
            scanf("%d",&value);
            enqueue(&qu, value);
            break;
        }
        case 2:{
            int val = dequeue(&qu);
            printf("%d has been dequeued from the Queue\n",val);
            break;
        }
        case 3:
            traverse(&qu);
            break;
        default:
            printf("Invalid Choice 404!!!\n");
    }    
    }
    return 0;
}