#include <stdio.h>
#include <malloc.h>

struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int val){
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    if(n == NULL){
        printf("Overflow!\n");
    }else{
        n->data = val;
        n->left = NULL;
        n->right = NULL;
    }
    return n;
}

int isBST(struct Node * root){
    static struct Node * prev = NULL; // creating a static node so that the it does not get created with every new call
    if(root != NULL){ // Check if root is NULL 
        if(!isBST(root->left)){ // if the left binary tree is not a binary search tree than what is the sense of checking ahead return 0;
            return 0;
        }
        if(prev != NULL && root->data <= prev->data){ // also check if the root node data is greater than previous node data
            return 0;
        }
        // after checking of left subtree now come to the root
        prev = root;
        // and then check of right subtree
        return isBST(root->right);
    }else{
        // if root is NULL that the last node has been hit it is a binary search tree
        return 1;
    }
} 

int main(){    
    struct Node * p1 = createNode(5);
    struct Node * p2 = createNode(3);
    struct Node * p3 = createNode(6);
    struct Node * p4 = createNode(2);
    struct Node * p5 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  2   4  
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;

    if(isBST(p1)){
        printf("It is a Binary Search Tree!!\n");
    }else{  
        printf("It is not a Binary Search Tree!!\n");
    }
}