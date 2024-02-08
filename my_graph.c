#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"
#include "my_mat.c"
int main() {
    //int i, j;
    char choice;
   
    int **Matrix;
    //
    int** rows=(int**)malloc(MATRIX_SIZE * sizeof(int*));
    int *cols;
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        cols=(int*) malloc(MATRIX_SIZE * sizeof(int));
        rows[i] = cols;
    }
    Matrix=rows;

    do 
    {
        scanf("%c", &choice);

        switch (choice)
        {
            case 'A':
            {
                getMatFromUser(Matrix, MATRIX_SIZE);
                break;
            }

            case 'B':
            {
                int src,dest;
                    printf("enter i, j");
                    scanf("%d",&src);
                    scanf("%d",&dest);
                    isPath(Matrix,src,dest,MATRIX_SIZE);
                break;
            }

            case 'C':
            {
                //shortPathByDij(Matrix, MATRIX_SIZE);
                    int src,dest;
                    printf("enter i, j");
                    scanf("%d",&src);
                    scanf("%d",&dest);
                    findShortestPath(Matrix,src,dest,MATRIX_SIZE);
                    // dijkstra(Matrix, source_vertex, destination_vertex);
                    break;
            }

      
        }
    }

    while(choice != 'D');

    // Free memory to end program
    for (int i = 0; i < MATRIX_SIZE; ++i)
        free(Matrix[i]);

    free(Matrix);
    return 0;
}