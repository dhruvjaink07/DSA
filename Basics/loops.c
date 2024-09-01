#include <stdio.h>

int main(){
    int i =0;
    printf("while loop");
    while(i < 5){
        printf("%d\t", i);
        i++;
    }
    printf("\n");
    printf("do while loop");
    i = 5;
    do{
        printf("%d\t",i);
    }while(i < 5);
    printf("\n");
    printf("for loop");
    for(int i = 0; i < 10; i+=2){
        printf("%d\t",i);
    }
    return 0;
}