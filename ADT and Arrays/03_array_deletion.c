#include <stdio.h>

void display(int arr [], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void indDeletion(int arr [], int size, int index){
    for(int i = index; i < size - 1; i++){ // so why size -1  because when we be reaching the last size we wont have any element there as it will be shifted to one position left right! and that is why it has to be size - 1
        arr[i] = arr[i+1];
    }
}

int main(){
    int arr [] = {7,8,12,27,34};
    int size = 5, index = 2;
    display(arr,size);
    indDeletion(arr, size, index);
    size-=1; // after deletion decrement the size by 1
    display(arr,size);
    return 0;
}