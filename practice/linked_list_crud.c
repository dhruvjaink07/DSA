#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void traverse(struct Node* ptr){
    while(ptr != NULL){
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertFirst(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    head = ptr;
    return head;
}

struct Node * insertAtIndex(struct Node * head, int data, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;
    int i = 0;
    while(i < index-1){
        p = p->next;
        i++;
    }   
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node * insertLast(struct Node * head,int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * q = head->next;
    while(q->next!=NULL){
        q = q->next;
    }
    q->next = ptr;
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

struct Node * deleteFirst(struct Node * head){
    struct Node * ptr = head;
    head = head -> next;
    free(ptr);

    return head;
}

struct Node * deleteAtIndex(struct Node * head, int index){
    struct Node * ptr = head;
    struct Node * p = head->next;
    for(int i = 0; i <  index-1; i++){
        p = p->next;
        ptr = ptr->next;
    }
    ptr->next = p->next;
    free(p);

    return head;
}

struct Node * deleteLast(struct Node * head){
    struct Node * p = head;
    struct Node * q = head -> next;
    while(q->next != NULL){
        p=p->next;
        q=q->next;
    }
    p->next = NULL;

    free(q);

    return head;
}

struct Node * deleteAtValue(struct Node * head, int data){
    struct Node * p = head;
    struct Node * q = head->next;

    while(q->data != data && q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data == data){
        p->next = q->next;
        free(q);
    }

    return head;
}
int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head -> data = 6;
    head -> next = second;

    second -> data = 12;
    second -> next = third;

    third -> data = 16;
    third -> next = fourth;

    fourth -> data = 26;
    fourth -> next = NULL;

    printf("Linked List Before Deletion\n");
    traverse(head);
    // head = insertFirst(head, 62);
    // head = insertAtIndex(head, 62,1);
    // head = insertLast(head, 62);
    // head = insertAfter(head, third, 62);

    // head = deleteFirst(head);
    // head = deleteAtIndex(head,2);
    // head = deleteLast(head);
    head = deleteAtValue(head, 12);

    printf("Linked List After Deletion\n");
    traverse(head);

    return 0;
}