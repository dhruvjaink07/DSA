#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void linkedListTraverse(struct Node * ptr){
    while(ptr != NULL){
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
/*
    This Function will delete the first element in LinkedList by moving the head to next node 
    and storing head in ptr so that it can be free() to release memory
 */
struct Node * deletionAtBegin(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
/*
    This function will take head pointer and index value to delete the value at the index
    Here we will take two pointers one will point to head and another will point to the next Node of head Node
    after running the loop till index - 1 times the pointer which points to head will be one element before the
    Node to be delete and another pointer will be exactly the Node to be deleted
    now the first pointer will be made to point the next of the another pointer that is 'q' and then release it
    and return head
*/
struct Node * deleteAtIndex(struct Node * head, int index){
    struct Node * p = head;
    struct Node * q = head->next;
    for(int i= 0; i<index-1; i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

/*
    This function will delete the last NODE of the list so 'p' will point at head and 'q' will point to next element
    of head and the while loop will run until 'q'-> next != NULL that means 'p' will be the second last element in the list
    after loop completion make 'p'->next = NULL so it becomes the last element in the list and then release 'q'
*/
struct Node * deleteAtEnd(struct Node * head){
    struct Node * p = head;
    struct Node * q = head->next;

    while(q->next!=NULL){
        p = p -> next;
        q = q -> next;
    }
    p->next = NULL;
    free(q);
    return head;
}
/*
    This function will delete the Node based on the Value. Same two pointers will be created, one will point to head and second will
    point to next of head and then loop will run the data of another Node != the value provided and q->next != NULL till then in the both pointers will move towards NULL one by one
    as the data matches the loop will break and then the next of previous element will become the next of another element
    and then the another element will be released
*/
struct Node * deleteAtValue(struct Node * head, int value){
    struct Node * p = head;
    struct Node * q = head->next;

    while(q->data != value && q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    // Do this to check if the data not match and the List has reached it's end so if the data of 'q' equals to the 
    // value perform deletion else do nothing , if we do not do this check it will always the delete the last node
    // even if the value does not match the data
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;

}
int main(){
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * second = (struct Node *)malloc(sizeof(struct Node));
    struct Node * third = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fifth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 6;
    head->next = second;

    second->data=12;
    second->next=third;

    third->data=16;
    third->next=fourth;

    fourth->data=26;
    fourth->next=fifth;

    fifth->data=62;
    fifth->next=NULL;

    printf("LinkedList Before Deletion\n");
    linkedListTraverse(head);
    // head = deletionAtBegin(head);
    // head = deleteAtIndex(head, 1); // Will Not work for first element
    // head = deleteAtEnd(head); // Will Not work for first element
    head = deleteAtValue(head, 96); // Will Not work for first element
    printf("LinkedList After Deletion\n");
    linkedListTraverse(head);
    return 0;
}