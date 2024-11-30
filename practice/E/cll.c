#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *head;

Node *createNode(int data)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}
void traverse(Node *head)
{
    if (head == NULL)
    {
        printf("List Empty\n");
        return;
    }
    Node *temp = head;
    do
    {
        printf("Data: %d\n", temp->data);
        temp = temp->next;
    } while (temp != head);
}
void insertAtEnd(Node **head, int data)
{
    Node *n = createNode(data);
    if (*head == NULL)
    {
        *head = n;
        n->next = *head;
        return;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != *head){ 
            temp = temp->next;
        }

        temp->next = n;
        n->next = *head;
    }
}

void deleteAtStart(Node ** head){
    if(*head == NULL){
        printf("UnderFlow!");
        return ;
    }else{
        Node * temp = *head;
        Node * temp2 = (*head)->next;
        while(temp2->next != *head){
            temp2 = temp2->next;
        }
        *head = (*head)->next;
        temp2 -> next = *head;
        free(temp);
        return ;
    }
}
int evenDataNodes(Node * head){
    if(head == NULL){
        printf("Underflow!");
        return -1;
    }
    int count = 0;
    Node * temp = head;
    do{
        if(temp->data%2==0){
            count++;
        }
        temp = temp->next;
    }while(temp != head);
    return count;
}
int main()
{
    insertAtEnd(&head, 16);
    insertAtEnd(&head, 71);
    insertAtEnd(&head, 74);
    traverse(head);
    // printf("After Deletion\n");
    // deleteAtStart(&head);
    // traverse(head);
    printf("Even elements in LinkedList: %d\n",evenDataNodes(head));
}