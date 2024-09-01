#include <stdio.h>

void display(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int indInsertion(int arr[], int size, int element, int index, int total_size){
    if(size >= total_size){ // here we will check the use size is being greater than the total capacity we have reserved for the array
        return -1;
    }

    // use to traverse the array from the end till the ith value is greater than equal to index where we want to insert the element 
    for(int i = size-1; i >= index; i--){
        // now shifting element towards right size until the index is being empty
        arr[i+1] = arr[i];
    }
    // after shifting the element now insert the element at the desired index
    arr[index] = element;
    return 0;
}
int main(){
    int arr[100] = {7,8,12,27,88};
    int size = 5, element = 45, index = 3;
    display(arr, size);
    int isInserted = indInsertion(arr, size, element, index, 100);
    size +=1; // after inserting the element increment the size value to keep track of used size
    isInserted >= 0 ? display(arr, size) : printf("Can\'t insert the element due to array capacity is overflowed\n");

    return 0;
}