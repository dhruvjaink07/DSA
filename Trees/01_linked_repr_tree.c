#include <stdio.h>
#include <malloc.h>

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int data){
    struct Node * n; // Creating Node
    n = (struct Node *)malloc(sizeof(struct Node)); // allocating memory for node
    // Setting up nodes properties
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

int main(){
    // Constructing node using function
    struct Node * p1 = createNode(34);
    struct Node * p2 = createNode(44);
    struct Node * p3 = createNode(54);
    struct Node * p4 = createNode(64);
    struct Node * p5 = createNode(74);

    // Linking Nodes with left and right children
    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p2->right = p5;

    return 0;
}