#include <stdio.h>
#include <string.h>

int main(){
    char str1 [40] = "Dhruv Jain";
    char str2 [20];

    // function to copy string
    strcpy(str2, str1);
    printf("%s\n",str2);

    // to compare two strings returns 0 if true and 1 vice-versa
    printf("%d\n", strcmp(str1, str2));

    // to get the length of string
    printf("%d\n", strlen(str2));

    strcat(str1," and I am Software Developer");
    printf("%s",str1);
    return 0;
}