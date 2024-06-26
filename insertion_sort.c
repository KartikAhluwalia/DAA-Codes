#include<stdio.h>

void insertion_sort(int arr[],int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in the array ");
    scanf("%d",&n);
    int arr[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insertion_sort(arr,n);
    printf("\nAfter Sorting : ");
    for(i=0;i<n;i++){
        printf("%d \t",arr[i]);
    }
    return 0;
}
