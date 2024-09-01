#include <stdio.h>

int x = 5;
// Function Declaration
void sayMyName(char name[]);
void myFunction(char name[]){
    printf("I just got executed by %s\n", name);
}

int sum(int a, int b) {
    return a + b;
}

int max(int *arr, int size) {
    if (size == 0) {
        return -1;
    }
    int max = arr[0];  
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    myFunction("Dhruv");
    printf("%d\n", sum(3, 4));
    int arr[] = {34, 5, 6, 66, 56};
    int size = sizeof(arr) / sizeof(arr[0]);  

    printf("%d is the maximum number in array\n", max(arr, size));
    printf("%d\n", x); // Will print the global scope
    int x = 6;
    printf("%d\n",x);  // Will print the local scope
    sayMyName("Dhruv");
    return 0;
}

void sayMyName(char name[]){
    printf("You are %s", name);
}