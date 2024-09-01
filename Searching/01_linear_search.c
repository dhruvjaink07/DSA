#include <stdio.h>
// Linear Search has time complexity of O(n)
int linearSearch(int arr [], int element, int length){
    for(int i = 0; i < length; i++){
        if(arr[i] == element){
            return i; // if element found return it's index 
        }
    }
    return -1; // else return -1 indicating the element not found in array
}

int main(){
    int arr [] = {7,8,12,27,34};
    int element = 12, length = sizeof(arr)/sizeof(arr[0]);
    int index = linearSearch(arr, element, length);
    printf("The element %d is at index %d\n", element, index);
    return 0;
}