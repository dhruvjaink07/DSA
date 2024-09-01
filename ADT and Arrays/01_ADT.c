// ADT means Abstract Data Type
// Typically used to hide the complications of how things work behind the scene and let the user use it without worry
#include <stdio.h>
#include <stdlib.h>

struct MyArray{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct MyArray *a, int tSize, int uSize){
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*ptr).ptr = (int *)malloc(tSize * sizeof(uSize));

    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void setVal(struct MyArray *a){
    int n;
    for(int i = 0; i < a->used_size; i++){
        printf("Enter element %d: ",i);
        scanf("%d",&n);
        a->ptr[i] = n;
    }
}
void show(struct MyArray *arr){
    for(int i = 0; i < arr->used_size; i++){
        printf("%d ",(arr->ptr)[i]);
    }
}
int main(){
    struct MyArray array;
    createArray(&array, 10, 5);
    setVal(&array);
    show(&array);
    return 0;
}