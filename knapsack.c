#include<stdio.h>
#include<time.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int W, int val[], int wts[], int n){
	if(n==0 || W==0){
		return 0;
	}
	if(W<wts[n-1]){
		return knapsack(W,val,wts,n-1);
	}
	else{
		return max(val[n-1]+knapsack(W-wts[n-1],val,wts,n-1),knapsack(W,val,wts,n-1));
	}
}

int main()
{
	int n=3;
	int profit[] = {20,15,30};
	int weight[] = {10,30,45};
	int max_wt = 45;

	printf("Max profit = %d",knapsack(max_wt,profit,weight,3));
	
	return 0;
}