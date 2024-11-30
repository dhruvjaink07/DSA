#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
struct Node * head;
struct Node * createNode(int data){
    struct Node * n = (struct Node *) malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}
void traverse(struct Node * head){
    struct Node * temp = head;
    while(temp != NULL){
        printf("Data: %d\n",temp->data);
        temp = temp->next;
    }
}
void insertAtStart(struct Node ** head, int data){
    if(*head == NULL){
        *head = createNode(data);
        return;
    }else{
        struct Node * p = createNode(data);
        p->next = *head;
        *head = p;
        return;
    }
}
void insertAtEnd(struct Node ** head, int data){
    if(*head == NULL){
        *head = createNode(data);
        return;
    }
    else{
        struct Node * p = createNode(data);
        struct Node * temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = p;
        return;
    }
}

void insertAtIndex(struct Node ** head, int data, int index){
    if(*head == NULL){
        *head = createNode(data);
        return;
    }else{
        struct Node * p = createNode(data);
        struct Node * temp1 = *head;
        struct Node * temp2 = (*head)->next;
        for(int i = 0; i < index -1; i++){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp1->next = p;
        p->next = temp2;
        return;
    }
}

void deleteAtStart(struct Node ** head){
    if(*head == NULL){
        printf("Linked List Underflow!");
        return;
    }
    struct Node * temp = *head;
    *head = temp->next;
    free(temp);
    return;
}
void deleteAtEnd(struct Node ** head){
    if(*head == NULL){
        printf("Linked List Underflow!");
        return;
    }
    struct Node * temp = *head;
    while(temp -> next->next != NULL){
        temp = temp -> next;
    }
    temp->next = NULL;
    free(temp->next);
}
void deleteAtIndex(struct Node ** head, int index){
    if(*head == NULL){
        printf("Linked List Underflow!");
        return;
    }
    struct Node * temp = * head;
    struct Node * temp2 = temp->next;
    for (int i = 0; i < index-1;i++){
        temp=temp->next;
        temp2=temp->next;
    }
    temp->next = temp2->next;
    free(temp2);
}
int search(struct Node * head, int value){
    struct Node * temp = head;
    while(temp != NULL){
        if(temp->data == value){
            return 1;
        }else{
            temp = temp->next;
        }
    }
    return 0;
}
int main(){
    printf("Singly LinkedList Insertion\n");
    insertAtStart(&head, 12);
    insertAtStart(&head,13);
    insertAtEnd(&head, 15);
    insertAtIndex(&head, 17, 2);
    // traverse(head);
    // printf("Singly LinkedList Deletion\n");
    // deleteAtStart(&head);
    // deleteAtEnd(&head);
    // deleteAtIndex(&head,2);
    // traverse(head);
    int res = search(head, 23);
    if(res){
        printf("Element found!\n");
    }else{
        printf("Element Not found!\n");
    }
    return 0;
}