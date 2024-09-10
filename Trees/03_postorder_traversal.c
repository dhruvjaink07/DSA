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

void postOrder(struct Node * root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d \t",root->data);
     }
}

int main(){
    // Constructing node using function
    struct Node * p1 = createNode(4);
    struct Node * p2 = createNode(1);
    struct Node * p3 = createNode(6);
    struct Node * p4 = createNode(5);
    struct Node * p5 = createNode(2);
    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2  

    // Linking Nodes with left and right children
    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p2->right = p5;

    postOrder(p1);
    return 0;
}