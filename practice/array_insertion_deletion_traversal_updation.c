#include <stdio.h>

void traverse(int arr [] , int size){
    for(int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void insertion(int arr[], int size, int capacity, int element, int index){
    if(size >= capacity){
        printf("ELement cannot be inserted in the Array\n");
    }
    for(int i = size -1; i >= index; i--){
        arr[i+1] = arr[i]; // Shifting elements to make empty space for insertion
    }
    arr[index] = element;
}

void updation(int arr[], int element, int index){
    arr[index] = element;
}

void deletion(int arr[], int size, int index){
    for(int i = index; i < size - 1; i++){
        arr[i] = arr[i+1];
    }
}

int main(){
    int arr [50] = {6,7,11,12,16,26,66};
    int size = 7, element = 77, index = 4;
    printf("Array Traversal\n");
    traverse(arr, size);
    printf("Array Insertion\n");
    insertion(arr, size, 50, element, index);
    size+=1;
    traverse(arr,size);
    printf("Array Updation\n");
    element = 99;
    updation(arr, element, index);
    traverse(arr,size);
    printf("Array Element Deletion\n");
    deletion(arr,size, index);
    size-=1;
    traverse(arr,size);
}