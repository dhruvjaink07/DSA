#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack{
    int size;
    int top;
    char * arr;
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

void push(struct Stack * ptr, char data){
    if(isFull(ptr)){
        printf("StackOverflow! Cannot insert %d\n",data);
    }else{
        ptr->top = ptr->top + 1;
        ptr->arr[ptr->top] = data;
    }
}

char pop(struct Stack *ptr){
    if(isEmpty(ptr)){
        printf("StackUnderFlow! Cannot pop element\n");
        return -1;
    }else{
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int parenthesisMatching(char * exp){
    // Created a Stack
    struct Stack * st = (struct Stack*)malloc(sizeof(struct Stack));
    st->size = strlen(exp);
    st->top = -1;
    st->arr = (char *)malloc(st->size * sizeof(char));

    for(int i = 0; exp[i]!='\0'; i++){
        if(exp[i] == '('){
            push(st, exp[i]);
        }else if(exp[i] == ')'){
            if(isEmpty(st)){
                return 0;
            }
            pop(st);
        }
    }
    if(isEmpty(st)){
        return 1;
    }else{
        return 0;
    }
}

int match(char a, char b){
    if(a=='(' && b == ')'){
        return 1;
    }
    if(a=='[' && b == ']'){
        return 1;
    }
    if(a=='{' && b == '}'){
        return 1;
    }
    return 0;
}
int multipleParenthesisMatching(char * exp){
    struct Stack * sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = strlen(exp);
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char val;
    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
            push(sp, exp[i]);
        } else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){
            if(isEmpty(sp)){
                return 0;
            } else {
                val = pop(sp);
                // Check for matching pairs
                if(!match(val, exp[i])){ 
                    return 0;
                }
            }
        }
    }
    if(isEmpty(sp)){
        return 1;
    } else {
        return 0;
    }
}

int main(){
    char * exp = "(3+4)+8";
    char * exp2 = "({x+2+[9*9]})";
    // if(parenthesisMatching(exp)){
    //     printf("The parenthesis is matching!\n");
    // }else{
    //     printf("The parenthesis is not matching!\n");
    // }

    if(multipleParenthesisMatching(exp2)){
        printf("The parenthesis is matching!\n");
    }else{
        printf("The parenthesis is not matching!\n");
    }
    return 0;
}