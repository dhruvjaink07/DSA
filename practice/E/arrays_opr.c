#include <stdio.h>
void display(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indInsert(int arr[], int size, int index, int totalSize, int element){
    if(size >= totalSize){
        return -1;
    }
    for(int i = size - 1; i >= index; i--){
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 0;
}

int deletion(int arr[], int size, int index){
    if(size <= 0){
        return -1;
    }
    for(int i = index; i <= size; i++){
        arr[i] = arr[i+1];
    }
    return 0;
}

int main() {
    int arr[7] = {4, 5, 6, 7, 8}; // Allocate space for 7 elements
    int size = 5; // Initial size of the array
    int totalSize = 7; // Total capacity of the array
    display(arr, size);
    int result = indInsert(arr, size, 3, totalSize, 1);   
    if(result == 0){
        size++; // Increment size after successful insertion
        printf("After Insertion\n");
        display(arr, size);
    } else {
        printf("Insertion failed. Array is full.\n");
    }
    deletion(arr,size,2);
    size--;
    display(arr,size);
    return 0;
}
