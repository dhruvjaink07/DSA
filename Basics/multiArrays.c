#include <stdio.h>
#include <stdbool.h> // for using boolean data type

int main() {
    int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };

    // Calculate the number of rows and columns correctly
    int rows = sizeof(matrix) / sizeof(matrix[0]);
    int cols = sizeof(matrix[0]) / sizeof(matrix[0][0]);

    // Print the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    bool valid = true;
    return 0;
}
