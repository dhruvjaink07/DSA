#include <stdio.h>
#include <malloc.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void traverse(struct Node *ptr){
    struct Node *temp = ptr;
    if(temp == NULL){
        printf("List is Empty\n");
        return;
    }
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node *createNode(int val){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = val;
    n->next = NULL;
    return n;
}

void insertAtBegin(struct Node **head, int data){
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node **head, int data){
    struct Node *newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtIndex(struct Node **head, int data, int index){
    struct Node *newNode = createNode(data);
    if(index == 0){
        insertAtBegin(head, data);
        return;
    }
    struct Node *temp = *head;
    for(int i = 0; i < index - 1 && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Index out of bounds\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBegin(struct Node **head){
    if(*head == NULL){
        printf("List is already empty\n");
        return;
    }
    struct Node *ptr = *head;
    *head = (*head)->next;
    free(ptr);
}

void deleteAtEnd(struct Node **head){
    if(*head == NULL){
        printf("List is already empty\n");
        return;
    }
    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *ptr = *head;
    struct Node *qtr = *head;
    while(qtr->next != NULL){
        ptr = qtr;
        qtr = qtr->next;
    }
    ptr->next = NULL;
    free(qtr);
}

void deleteAtIndex(struct Node **head, int index){
    if(*head == NULL){
        printf("List is already empty\n");
        return;
    }
    if(index == 0){
        deleteAtBegin(head);
        return;
    }
    struct Node *ptr = *head;
    struct Node *qtr = (*head)->next;
    for(int i = 0; i < index - 1 && qtr != NULL; i++){
        ptr = ptr->next;
        qtr = qtr->next;
    }
    if(qtr == NULL){
        printf("Index out of bounds\n");
        return;
    }
    ptr->next = qtr->next;
    free(qtr);
}

int main(){
    int choice, value, index;
    
    while(1){
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Index\n4. Delete at Beginning\n5. Delete at End\n6. Delete at Index\n7. Traverse\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBegin(&head, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter index: ");
                scanf("%d", &index);
                insertAtIndex(&head, value, index);
                break;
            case 4:
                deleteAtBegin(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                deleteAtIndex(&head, index);
                break;
            case 7:
                printf("The linked list is: ");
                traverse(head);
                break;
            case 8:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
