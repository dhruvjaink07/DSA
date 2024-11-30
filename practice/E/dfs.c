#include <stdio.h>
#include <stdlib.h>

int visited[7] = {0, 0, 0, 0, 0, 0, 0};

int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};

void DFS(int i)
{
    printf("%d", i); // Printing the Visited Nodes
    visited[i] = 1; // Marking the node Visited
    for (int j = 0; j < 7; j++)
    {
        // This condition says that wherever there is Edge present and which is not visited call the Same function (Recursion)
        if (a[i][j] == 1 && !visited[j])
        {
            DFS(j);
        }
    }
}

int main()
{
    // DFS Implementation
    DFS(0);
    return 0;
}