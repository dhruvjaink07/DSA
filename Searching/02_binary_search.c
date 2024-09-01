#include <stdio.h>
// NOTE Binary Search is always performed on a sorted array
// binary search has time complexity of O(logn)
int binarySearch(int arr [], int size, int element){
    int low = 0;
    int high = size -1;
    while(low <= high){
        int mid = low + (high - low) /2;
        if(arr[mid] > element){
            high = mid -1;
        }else if(arr[mid] < element){
            low = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}

int main(){
    int arr [] = {7,8,9,29,39,45,78,99};
    int element = 39, size = sizeof(arr)/sizeof(arr[0]);
    int index = binarySearch(arr, size, element);
    printf("The element %d is at index %d according to binary search\n", element ,  index);
    return 0;
}