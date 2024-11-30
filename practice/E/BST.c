#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *root = NULL;

Node *createNode(int key) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = key;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void insertNode(Node **root, int key) {
    Node *n = createNode(key);
    Node *current = *root;
    Node *prev = NULL;
    
    if (*root == NULL) {
        *root = n;
        return;
    }
    
    while (current != NULL) {
        prev = current;
        if (current->data == key) {
            printf("\nCannot Insert Duplicate elements\n");
            free(n);
            return;
        } else if (current->data > key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    if (prev->data > key) {
        prev->left = n;
    } else {
        prev->right = n;
    }
}

Node *search(Node *root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == key) {
        return root;
    } else if (root->data > key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

void traverse(Node *root) {
    if (root != NULL) {
        traverse(root->left);
        printf("%d ", root->data);
        traverse(root->right);
    }
}

void freeTree(Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

Node * inOrderPredecessor(Node * root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}
Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    // Search for the node to be deleted
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node found

        // Case 1: Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Node with two children
        Node* iPre = inOrderPredecessor(root);
        root->data = iPre->data; // Replace with in-order predecessor's value
        root->left = deleteNode(root->left, iPre->data); // Delete in-order predecessor
    }
    return root;
}

int main() {
    int choice, key, i = 1;
    Node *temp = NULL;

    printf("Select Your choice: \n1. Insert\n2. Search\n3. Traverse\n4. Deletion\n0. Quit\n");
    while (i) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insertNode(&root, key);
                printf("\n");
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                temp = search(root, key);
                if (temp != NULL) {
                    printf("Element %d found in the tree\n", temp->data);
                } else {
                    printf("KEY NOT FOUND!!\n");
                }
                break;

            case 3:
                traverse(root);
                printf("\n");
                break;

            case 4:
                printf("Enter key to be deleted: ");
                scanf("%d",&key);
                printf("\n");
                root = deleteNode(root,key);
                break;
            case 0:
                i = 0;
                freeTree(root);
                printf("Bye Bye!\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}
