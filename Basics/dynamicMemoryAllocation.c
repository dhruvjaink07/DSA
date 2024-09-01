#include <stdio.h>
#include <stdlib.h>

int main(){
    // Allocate dynamic memory based on the user entered size
    int sizeReserved;
    printf("Enter the Size to be reserved: ");
    scanf("%d", &sizeReserved);
    printf("\n");
    int *ptr = (int *)calloc(sizeReserved, sizeof(int));
    for(int i = 0; i < sizeReserved; i++){
        printf("Enter value of %d element: ", i);
        scanf("%d", &ptr[i]);
    }
    for(int i = 0; i < sizeReserved; i++){
        printf("The value of %d element is %d\n", i, ptr[i]);
    }
    return 0;
}