#include <stdio.h> 
#include <string.h>
// Structures are also like arrays but it can stored different data types of variable related to each other
struct MyStructure{ // Structure declaration
    int myNum; // Member (int variable)
    char myLetter; // Member (char variable)
    // We can't directly assign the value of String in the structure
    char name [30];
}; // end of structure


// Real life example
struct Car {
  char brand[50];
  char model[50];
  int year;
};

int main(){

    // Using structure
    struct MyStructure s1;
    struct MyStructure s2;
    // Assign Value to the member of structure
    s1.myNum = 6;
    s1.myLetter = 'D';
    strcpy(s1.name, "Dhruv");
    // We can use strcpy function for <string.h> library to do so
    s2.myNum = 7;
    s2.myLetter = 'H';

    // Print values
    // printf("%d\n",s1.myNum);
    // printf("%c\n", s1.myLetter);
    // printf("%s\n", s1.name);

    // printf("%d\n",s2.myNum);
    // printf("%c\n", s2.myLetter);
    
    // This was all one way
    // We have a much simpler way to do this
    struct MyStructure s3 = {26, 'T', "Tanish"};
    strcpy(s3.name, "Tony"); // modifying the String value 
    printf("%d %c %s\n",s3.myNum, s3.myLetter, s3.name);
    // Here the order of inserted value should match the order it is being declared
    // We can copy structure from one to another
    s1 = s3; // the copy of structure 3 is copied to structure 1
    printf("%d %c %s\n",s1.myNum, s1.myLetter, s1.name);
    
    struct Car car1 = {"BMW", "X5", 1999};
    struct Car car2 = {"Ford", "Mustang", 1969};
    struct Car car3 = {"Toyota", "Corolla", 2011};

    printf("%s %s %d\n", car1.brand, car1.model, car1.year);
    printf("%s %s %d\n", car2.brand, car2.model, car2.year);
    printf("%s %s %d\n", car3.brand, car3.model, car3.year);
    return 0;   
}