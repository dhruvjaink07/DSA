#include <stdio.h>

// Declaration of enum or also known as 'enumeration' they represent a group of constants
// By default the values starts from '0' but we can specify them
enum LEVEL {
    LOW = 25,
    MEDIUM = 50,
    HIGH = 75
};

int main(){
    enum LEVEL myEnum = LOW;
    printf("%d\n", myEnum);
    return 0;
}