#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"


 
void getMatFromUser(int** matrix, int size) {
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++){
            printf("matrix[%d][%d]: ",i,j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int dijkstra(int **matrix, int src, int dest,int len) {
    

    int dist[V],counter=0,min,u;
    bool sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

while (++counter < len)
    {
        min = INT_MAX;

        for (int vert = 0; vert < len; ++vert)
        {
            if (sptSet[vert] || dist[vert] > min)
                continue;

            min = dist[vert];
            u = vert;
        }

        sptSet[u] = true;

        for (int v = 0; v < len; v++)
        {
            if (sptSet[v] || !matrix[u][v] || dist[u] == INT_MAX || (dist[u] + matrix[u][v] >= dist[v]))
                continue;

            dist[v] = dist[u] + matrix[u][v];
        }
    }
 //printf("Shortest path from vertex %d to vertex %d:\n", src, dest);
   //printf("Distance: %d\n", dist[dest]);
    return dist[dest];
}

    int findShortestPath(int **matrix,int i,int j,int len){
        int ans= dijkstra(matrix,i,j,len);
        if(ans==0 || ans==INT_MAX){
            //printf("Distance: %d\n",-1);
            return -1;
        }
        else{
            //printf("Distance: %d\n",ans);
            return ans;
        }
        
    }




// Function to print the solution (distances from the source)
// void printSolution(int dist[], int n) {
//     printf("Vertex \tDistance from Source\n");
//     for (int i = 0; i < V; i++) {
//         printf("\t%d \t\t %d\n", i, dist[i]);
//     }
// }


void isPath(int** Matrix,int src,int dest,int size){
    int istrue = findShortestPath(Matrix,src,dest,size);
    if (istrue==-1)
    {
        printf("False");
    }
    else{
        printf("True");
    }
}