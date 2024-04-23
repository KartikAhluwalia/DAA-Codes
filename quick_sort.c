#include<stdio.h>

int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low;j<=high;j++){
        if(arr[j]<pivot){
            i++;
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp1 = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp1;
    return i+1;
}

void quick_sort(int arr[],int low,int high){
    if(low<high){
        int partition_index = partition(arr,low,high);

        quick_sort(arr,low,partition_index-1);
        quick_sort(arr,partition_index+1,high);
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
    quick_sort(arr,0,n-1);
    printf("\nAfter Sorting : ");
    for(i=0;i<n;i++){
        printf("%d \t",arr[i]);
    }
    return 0;
}
