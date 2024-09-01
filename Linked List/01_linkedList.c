#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void LinkedListTraversal(struct Node * ptr){
    while(ptr != NULL){
        printf("Element: %d\n",ptr->data);
        ptr = ptr -> next;
    }
}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    // Created three Nodes , which are available in the heap memory
    // or we can say Allocate Memory for nodes in LinkedList in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node  *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second Node
    head -> data=7;
    head -> next = second;

    // Link second and third Node
    second -> data = 16;
    second -> next=third;

    // Link third and fourth Node
    third -> data = 20;
    third -> next = fourth;

    // Terminate the list after fourth Node 
    fourth -> data=25;
    fourth -> next=NULL;

    LinkedListTraversal(head);
    return 0;
}