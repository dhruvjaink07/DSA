#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    int size;
    int top;
    char *arr;
} Stack;

int isEmpty(Stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(Stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(Stack *sp, char data)
{
    if (isFull(sp))
    {
        printf("StackOverFlow!!\n");
        return;
    }
    sp->top++;
    sp->arr[sp->top] = data;
}

char pop(Stack *sp)
{
    if (isEmpty(sp))
    {
        printf("StackUnderFlow!!\n");
        return -1;
    }
    char value = sp->arr[sp->top];
    sp->top--;
    return value;
}

int isOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
        return 1;
    }else{
        return 0;
    }
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
}

char stackTop(Stack * sp){
    return sp->arr[sp->top];
}

char * infixToPostfix(char * infix){
    Stack * sp = (Stack *)malloc(sizeof(Stack));
    sp->top = -1;
    sp->size = strlen(infix);
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char * postfix = (char *)malloc(strlen(infix) * sizeof(char));
    int i = 0; // to handle infix expression
    int j = 0; // to handle postfix expression

    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }else{
            if(precedence(infix[i]) > precedence(stackTop(sp))){
                push(sp,infix[i]);
                i++;
            }else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }

    postfix[j] = '\0';
    return postfix;
}

int main(){
    char * infix = "+a+b-c/d*l";
    printf("Postfix is %s\n", infixToPostfix(infix));

    return 0;
}