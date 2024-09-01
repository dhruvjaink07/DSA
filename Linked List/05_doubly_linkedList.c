#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * prev;
    struct Node * next;
};

void traverseDoubly(struct Node * ptr){
    printf("Doubly Linked List\n");
    while(ptr!=NULL){
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}

void reverseDoubly(struct Node * ptr){
    printf("Reverse Doubly Linked List\n");
    while(ptr!= NULL){
        printf("Element : %d\n",ptr->data);
        ptr = ptr->prev;
    }
}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));
 
    head -> prev = NULL;
    head -> data = 6;
    head -> next = second;

    second -> prev = head;
    second -> data = 12;
    second -> next = third;

    third -> prev = second;
    third -> data = 16;
    third -> next = fourth;

    fourth -> prev = third;
    fourth -> data = 26;
    fourth -> next = NULL;

    traverseDoubly(head);
    reverseDoubly(fourth);
    return 0;
}