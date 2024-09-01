#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next; // self referencing structure
};

void traverse(struct Node * ptr){
    while(ptr!=NULL){
        printf("Element : %d\n", ptr->data);
        ptr = ptr -> next;
    }
}

struct Node * insertAtBegin(struct Node * head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr -> next = head;
    return ptr;
}
struct Node * insertBetween(struct Node * head, int data, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;
    int i = 0;
    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    
    return head;
}

struct Node * insertAtEnd(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;
    int i = 0;
    while(p->next!=NULL){
        p = p->next;
        i++;
    }
    p->next = ptr;
    ptr->next = NULL;

    return head;
}

struct Node * insertAfter(struct Node * head, struct Node * prevNode, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
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
 
    head -> data = 6;
    head -> next = second;

    second -> data = 12;
    second -> next = third;

    third -> data = 16;
    third -> next = fourth;

    fourth -> data = 26;
    fourth -> next = NULL;

    printf("Linked List before insertion\n");
    traverse(head);
    // head = insertAtBegin(head, 57);
    // head = insertBetween(head,57,2);
    // head = insertAtEnd(head, 57);
    head = insertAfter(head, third, 57);
    printf("Linked List after insertion\n");
    traverse(head);
    return 0;
}