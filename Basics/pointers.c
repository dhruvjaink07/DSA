// Memory Address and pointers in this code
#include <stdio.h>

int main(){

    int myAge = 19;
    int* ptr = &myAge;
    // '&' is a reference operator which is used to get the memory address of the variable
    // '*' is a dereference operator which is used to get the value at the memory address
    /*
    Note that the * sign can be confusing here, as it does two different things in our code:

    When used in declaration (int* ptr), it creates a pointer variable.
    When not used in declaration, it act as a dereference operator.
     */
    // Memory location where the variables is stored
    // printf("%p\n", &myAge);
    // printf("%p\n", ptr);
    // printf("Value is ");
    // printf("%d\n", *ptr);
    // printf("%p\n", &ptr);
    
    int myNumbers[] = {25, 50, 75, 100};
    printf("%p address of array\n",myNumbers);
    for(int i = 0; i < sizeof(myNumbers)/ sizeof(myNumbers[0]); i++){
        printf("%p\n", &myNumbers[i]);
    }
    // This example proves that the address of array is basically the address of the first element in array and so from there are the consecutive blocks of memory are associated with arrays
    *(myNumbers+1) = 46;
    printf("%d\n", *(myNumbers + 1));
    return 0;
}