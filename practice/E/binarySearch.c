#include <stdio.h>

int binarySearch(int a[], int size, int el){
    int start = 0;
    int end = size - 1;

    while(start <= end){
        int mid = start + (end - start)/ 2;
        if(a[mid] > el){
            end = mid - 1;
        }else if(a[mid] < el){
            start = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}

int main(){
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int size = sizeof(a)/sizeof(a[0]);
    int el = 7;
    int result = binarySearch(a, size,el);
    if(result >= 0){
        printf("Element %d is on index %d\n",el,result);
    }else{
        printf("Element not found!!\n");
    }
    return 0;
}