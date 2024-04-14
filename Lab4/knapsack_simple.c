#include<stdio.h>
#include<stdlib.h>

//Time Complexity : O(2^n)

int max(int a, int b){
    return (a>b)?a:b;
}

int knapsack(int W, int n, int profit[], int weights[]){
    if(n==0 || W==0){
        return 0;
    }
    if(weights[n-1]>W){
        return knapsack(W,n-1,profit,weights);
    }
    else{
        return max(profit[n-1]+knapsack(W-weights[n-1],n-1,profit,weights),knapsack(W,n-1,profit,weights));
    }
}
int main(){
    int n,W;
    printf("Enter the number of objects : ");
    scanf("%d",&n);
    printf("\nEnter the Maximum weight of the bag : ");
    scanf("%d",&W);
    int i;
    int weights[n],profit[n];
    for(i=0;i<n;i++){
        printf("Weight of Object %d is ",i+1);
        scanf("%d",&weights[i]);
    }
    printf("\n");
    for(i=0;i<n;i++){
        printf("Profit of Object %d is ",i+1);
        scanf("%d",&profit[i]);
    }
    printf("\nMax Profit = %d",knapsack(W,n,profit,weights));
    return 0;
}
