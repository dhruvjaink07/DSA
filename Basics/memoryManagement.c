#include <stdio.h>
#include <stdlib.h>

int main(){
    // static memory allocation
    // int student[20];
    // printf("%lu", sizeof(student));

    // MALLOC used for dynamic memory allocation
    // printf("The size of int on my PC is %d\n", sizeof(int));
    // int *ptr;
    // ptr = (int *)malloc(6 * sizeof(int));
    // Well now the dynamically allocated memory can be used as array now
    // for(int i = 0; i < 6; i++){
    //     printf("Enter value of %d element: ", i);
    //     scanf("%d", &ptr[i]);
    // }
    // for(int i = 0; i < 6; i++){
    //     printf("The value of %d element is %d\n", i, ptr[i]);
    // }

    // float *ptr;
    // ptr = (float *)malloc(5 * sizeof(float));
    // for(int i = 0; i < 5; i++){
    //     printf("Enter value of %d element: ", i);
    //     scanf("%f", &ptr[i]);
    // }
    // for(int i = 0; i < 5; i++){
    //     printf("The value of %d element is %.3f\n", i, ptr[i]);
    // }

    // calloc() is a hatke function it does same as the malloc does for continuos memory allocation but initializes each block with default value of 0
    int *cal;
    cal = (int *)calloc(6, sizeof(int));
    // But if we didn't even give the value then also it will give them 0 as default value
    // for(int i = 0; i < 6; i++){
    //     printf("Enter value of %d element: ", i);
    //     scanf("%d", &cal[i]);
    // }
    for(int i = 0; i < 6; i++){
        printf("The value of %d element is %d\n", i, cal[i]);
    }

    // If there is no memory remained for allocation the function for allocation will return a NULL pointer
    return 0;
}