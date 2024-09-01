#include <stdio.h>

int main() {
    int userAge;
    printf("Check if you are eligible to vote: ");
    scanf("%d", &userAge); // Correct usage of scanf

    // Check voting eligibility using if-else
    // if (userAge >= 18) {
    //     printf("You can Vote!!!\n");
    // } else {
    //     printf("You cannot Vote!!!\n");
    // }

    // Alternative way using the switch statement
    switch(userAge) {
        case 19:
            printf("You are 19 years old and you can vote\n");
            break;
        case 17:
            printf("You are 17 years old and you cannot vote\n");
            break;
        default:
            if (userAge >= 18) {
                printf("You are eligible to vote\n");
            } else {
                printf("You are not eligible to vote\n");
            }
            break;
    }

    return 0;
}
