#include<stdio.h>

void selection_sort(int arr[],int n)
{
    int i,j;
    int min_ind,temp;
    for(i=0;i<n-1;i++){
        min_ind = i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min_ind]){
                min_ind = j;
            }
            temp = arr[i];
            arr[i] = arr[min_ind];
            arr[min_ind] = temp;
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
    selection_sort(arr,n);
    printf("\nAfter Sorting : ");
    for(i=0;i<n;i++){
        printf("%d \t",arr[i]);
    }
    return 0;
}
