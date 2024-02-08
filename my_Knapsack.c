#include "my_mat.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// #include "my_mat.c"
#define LEN 5
#define W 20
#define CHAR_MAX 20
    // int val[] = {35, 60, 100, 120, 130};
    // int wt[] = {2, 5, 6, 9,10};
    
    // int n = sizeof(val) / sizeof(val[0]);


void setItems(char* items,int* value,int* weight, int len){
        for (int i = 0; i < len; ++i)
    {
        printf("items[%d]: ",i);
        scanf(" %c",&items[i]);
    
    
        printf("value[%d]: ",i);
        scanf(" %d",&value[i]);
    
        printf("weight[%d]: ",i);
        scanf(" %d",&weight[i]);
    }  
}
int max(int a, int b) {
    return (a > b) ? a : b;
}
int knapSack (int weights[], int values[] , int selected_bool[]){
  int i,w=0;

  int K[LEN+1][W+1] = {0};
            
    // Build table K[][] in bottom up manner
    for (i = 0; i <= LEN; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i==0 || w==0){
                //selected[i] = 1;
                K[i][w] = 0;
            }
            else if (weights[i-1] <= w){
                selected_bool[i] = 1;
                K[i][w] = max(values[i-1] + K[i-1][w-weights[i-1]], K[i-1][w]);
            }
            else{
                selected_bool[i]=0;
                K[i][w] = K[i-1][w];
                }
        }
     }
    //printf("\nItems selected : ");
    int tempW = W;
    int y = 0; //to index in selected
    for (int x = LEN; x > 0; x--){
        if ((tempW-weights[x-1] >= 0) && (K[x][tempW] - K[x-1][tempW-weights[x-1]] == values[x-1]) ){
            selected_bool[y++] = x-1; //store current index and increment y
            tempW-=weights[x-1];
        }
    }
    int arr[5]={0};
 for(int j = y-1; j >= 0; j-- ){
   
    arr[selected_bool[j]]=1;
   
    //printf("%d",(selected_bool[j]) );

 }
 for(int i=0;i<5;i++){
    selected_bool[i]=arr[i];
 }
//   printf("%d",(selected_bool[0]) );
//    printf("%d",(selected_bool[1]) );
//    printf("%d",(selected_bool[2]) );
//    printf("%d",(selected_bool[3]) );
//    printf("%d",(selected_bool[4]) );

   return K[LEN][W];




}




int main() {
   
    char* items =  (char*)malloc(LEN * sizeof(char));
    int* value =  (int*)malloc(LEN * sizeof(int));
    int* weight =  (int*)malloc(LEN * sizeof(int));
    setItems(items,value,weight,LEN);
    int result[CHAR_MAX] = {0};
    int res = knapSack( weight, value, result);
    printf("Maximum profit: %d\n", res);

    printf("Selected items: ");
    for(int j = 0; j<5; j++){
        
            if(result[j]){
       
         printf(" %c",items[j]);}
        

    }
   
    free(items);
    free(value);
    free(weight);

return 0;

}