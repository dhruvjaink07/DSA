#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * prev;
    struct node * next;
};
struct node * head;
struct node * createNode(int data){
    struct node * n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->prev = NULL;
    n->next = NULL;
    return n;
}
void traverse(struct node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL) {
        printf("Data: %d\n", temp->data);
        temp = temp->next;
    }
}
void insertAtEnd(struct node **head, int data) {
    struct node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
void deleteAtStart(struct node ** head){
    if(*head == NULL){
        printf("LinkedList Underflow");
        return;
    }
    struct node * temp = *head;
    *head = (*head)->next;
    free(temp);
}
void deleteAfter(struct node ** givenNode){
    if(*givenNode == NULL || (*givenNode)->next == NULL){
        printf("Cannot perform deletion as either the given or it's next node is NULL\n");
        return ;
    }
    else{
        struct node * temp = (*givenNode)->next;
        (*givenNode)->next = temp->next;
        free(temp);
        return;
    }
}
int smallestData(struct node * head){
    struct node * temp = head;
    int min = temp->data;

    if(head == NULL){
        printf("Underflow!");
        return -1;
    }else{
        while(temp != NULL){
            if(temp->data < min){
                min = temp->data;
            }
            temp = temp->next;
        }
    }
    return min;
}
int main(){
    printf("Insertion\n");
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 17);
    insertAtEnd(&head, 32);
    insertAtEnd(&head, 27);
    // printf("Smallest Data: %d\n",smallestData(head));
    // traverse(head);
    // deleteAtStart(&head);
    // printf("Deletion\n");
    deleteAfter(&head->next);
    traverse(head);
    return 0;   
}