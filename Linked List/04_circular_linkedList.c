#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void traverseCircularLinkedList(struct Node * head){
    struct Node * ptr = head;
    do{
        printf("Element : %d\n", ptr->data);
        ptr = ptr-> next;
    }while(ptr!=head); // run it till the pointer is not equal to the head again that will be the one time traversal to circular linkedlist
}

struct Node * insertAtFirst(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = head->next;
    while(p->next!=head){
        p = p->next;
    }
    // Now at this point p points to the last Node od the list
    p->next = ptr; // so point the next of last Node to ptr
    ptr->next = head; // point the next of ptr to head 
    head = ptr; // and now so point the head to ptr to make it the first Node
    return head; 
    
}
struct Node * insertAtIndex(struct Node * head, int data, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = head;
    for(int i = 0; i < index - 1; i++){
        p = p->next;
    }
    // Now we are one index behind where we want to insert the element 
    ptr->next = p->next; // Now the next of ptr would be the next of p
    p->next = ptr; // and next of p would be ptr 
    // BOOM element inserted in between
    return head;
}

struct Node * insertAtEnd(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = head->next;
    while(p->next!=head){
        p=p->next;
    }
    // Now we are at the last node
    p->next = ptr;
    ptr->next = head;

    return head;
}

struct Node * insertAfter(struct Node * head, struct Node * prevNode, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

struct Node * deleteAtBegin(struct Node * head){
    struct Node * ptr = head;
    
    struct Node * p = head->next;
    while(p->next != head){
        p= p->next;
    }
    head = head->next;
    p->next = head;

    free(ptr);
    return head;
}

struct Node * deleteAtIndex(struct Node * head, int index){
    struct Node * p = head;
    struct Node * q = head->next;
    int i = 0;
    while(i < index -1 && q!=head){
        p=p->next;
        q=q->next;
        i++;
    }
    // p will be one element before the node to be deleted and q will be the Node to be deleted
    p->next = q->next;
    free(q);

    return head;
}

struct Node * deleteAtEnd(struct Node * head){
    struct Node * p = head;
    struct Node * q = head->next;

    while(q->next!=head){
        p = p -> next;
        q = q -> next;
    }
    p->next = head;
    free(q);
    return head;
}

struct Node * deleteAtValue(struct Node * head, int value){
    struct Node * p = head;
    struct Node * q = head->next;

    while(q->data != value && q!=head){
        q = q->next;
        p = p->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
    }

    return head;
}
int main(){
    struct Node * head = (struct Node*)malloc(sizeof(struct Node));
    struct Node * second = (struct Node*)malloc(sizeof(struct Node));
    struct Node * third = (struct Node*)malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node*)malloc(sizeof(struct Node));

    // This is a circular linkedlist where the last node points to the first node or we say it as head
    head->data = 6;
    head->next = second;

    second->data=12;
    second->next=third;

    third->data=16;
    third->next=fourth;

    fourth->data=26;
    fourth->next=head;
    
    printf("Circular LinkedList Before Deletion\n");
    traverseCircularLinkedList(head);
    // head = insertAtFirst(head, 62);
    // head = insertAtIndex(head,62,2);
    // head = insertAtEnd(head,62);
    // head = insertAfter(head,third,62);

    // head = deleteAtBegin(head);
    // head = deleteAtIndex(head, 2);
    // head = deleteAtEnd(head);
    head = deleteAtValue(head,16);
    printf("Circular LinkedList after Deletion\n");
    traverseCircularLinkedList(head);
    return 0;
}