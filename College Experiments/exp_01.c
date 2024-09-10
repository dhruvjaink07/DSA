#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Stack{
    int top;
    int size;
    int * arr;
};

int isEmpty(struct Stack * ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

int isFull(struct Stack * ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    return 0;
}

void push(struct Stack *s, int data){
    if(isFull(s)){
        printf("Stack Overflow!\n");
        return ;
    }else{
        s->top++;
        s->arr[s->top] = data;
    }
}

int pop(struct Stack * s){
    if(isEmpty(s)){
        printf("Stack Empty!\n");
        return -1;
    }else{
        int send = s->arr[s->top];
        s->top--;
        return send;
    }
}

int stackTop(struct Stack * s){
    return s->arr[s->top];
}

int stackBottom(struct Stack * s){
    return s->arr[0];
}

void traverse(struct Stack * s){
    if(s->top == -1){
        printf("Stack Empty!\n");
        return ;
    }
    printf("Printing Stack...\n");
    for(int i = 0; i <= s->top; i++){
        printf("%d\t",s->arr[i]);
    }
    printf("\n");
}

int main(){
    int tSize;
    printf("Size of Stack Must be...\n");
    scanf("%d", &tSize);    

    struct Stack * s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = tSize;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

     printf("Enter 1 for pushing elements\n");
     printf("Enter 2 for popping out element\n");
     printf("Enter 3 to get the stackTop\n");
     printf("Enter 4 to get the stackBottom\n");
     printf("Enter 5 to traverse the stack\n");
     printf("Enter 0 to quit\n");

    int i = 1;
    while(i){
    int choice;
    printf("Enter your choice:");
    scanf("%d",&choice);
    printf("\n");
    switch(choice){
        case 0:{
            printf("Bye Bye\n");
            i=0;
            break;
        }
        case 1:{
            int value;
            printf("Enter Value: \n");
            scanf("%d",&value);
            push(s,value);
            break;
        }
        case 2:{
            int val = pop(s);
            printf("%d has been popped from the stack\n",val);
            break;
        }
        case 3:
            printf("The element at stack top is %d\n",stackTop(s));
            break;
        case 4:
            printf("The element at stack bottom is %d\n",stackBottom(s));
            break;
        case 5:
            traverse(s);
            break;
        default:
            printf("Invalid Choice 404!!!");
    }    

    }

    free(s->arr);
    free(s);
    getch();
    return 0;

}