#include <stdio.h>

int main(){
    int myNumbers[] = {25, 50, 75, 100};
    int length = sizeof(myNumbers) / sizeof(myNumbers[0]);
    // printf("%d",length);
    for(int i = 0; i < length; i++){
        printf("%d\t", myNumbers[i]);
    }
    printf("\n");
    // A real life example
    int ages[] = {20, 22, 18, 35, 48, 26, 87, 70};
    int agesLength = sizeof(ages)/ sizeof(ages[0]);

    int sum = 0;
    for(int i = 0; i < agesLength; i++){
        sum += ages[i];
    }
    float avg = (float)sum / agesLength;
    printf("Average age is %.2f: ",avg);
    return 0;
}