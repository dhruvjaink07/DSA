#include <stdio.h>

int main(){
    int myAge = 19;
    printf("%d\n", myAge); // using format specifiers
    char c = 'A';
    printf("%c\n", c);
    char name[] = "Dhruv Jain"; // This is how we declare String in C as there is no built-in type of String data Type in C 
    printf("Hello World my name is %s and I am %d years old!",name, myAge);
    return 0;
}