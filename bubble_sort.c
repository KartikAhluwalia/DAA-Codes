#include<stdio.h>

void bubble_sort(int arr[],int n)
{
    int i,j;
    int temp;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
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
    bubble_sort(arr,n);
    printf("\nAfter Sorting : ");
    for(i=0;i<n;i++){
        printf("%d \t",arr[i]);
    }
    return 0;
}
