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

int main() {
    // Declare and initialize the queue
    Queue q;
    q.size = 400;           // Set the maximum size of the queue
    q.f = q.r = 0;          // Initialize front and rear to 0
    q.arr = (int*)malloc(sizeof(int) * q.size);  // Allocate memory for the queue

    // BFS implementation starts here
    int node;               // Variable to hold the current node being explored
    int i = 3;              // Start BFS from node 3 (0-indexed)
    int visited[7] = {0,0,0,0,0,0,0};  // Array to keep track of visited nodes, all initialized to 0

    // Adjacency matrix representing the graph
    int a[7][7] = {
        {0,1,1,1,0,0,0},    // Connections for node 0
        {1,0,1,0,0,0,0},    // Connections for node 1
        {1,1,0,1,1,0,0},    // Connections for node 2
        {1,0,1,0,1,0,0},    // Connections for node 3
        {0,0,1,1,0,1,1},    // Connections for node 4
        {0,0,0,0,1,0,0},    // Connections for node 5
        {0,0,0,0,1,0,0}     // Connections for node 6
    };

    // Print the starting node and mark it as visited
    printf("%d", i);        // Print the starting node (3)
    visited[i] = 1;         // Mark node 3 as visited

    // Enqueue the starting node for exploration
    enqueue(&q, i);

    // While the queue is not empty, process nodes layer by layer
    while (!isEmpty(&q)) {
        // Dequeue a node from the queue
        int node = dequeue(&q);

        // Explore all neighbors of the current node
        for (int j = 0; j < 7; j++) {
            // Check if there's an edge to node `j` and if `j` is not visited
            if (a[node][j] == 1 && visited[j] == 0) {
                // Print the neighbor node
                printf("%d", j);
                // Mark the neighbor as visited
                visited[j] = 1;
                // Enqueue the neighbor for further exploration
                enqueue(&q, j);
            }
        }
    }

    return 0;
}
