#include<stdio.h>

int binary_search(int arr[],int low, int high, int k)
{
    while(low<=high){
        int mid = (high+low)/2;
        if(arr[mid]==k){
            return mid;
        }
        else if(k>arr[mid]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

int main()
{
    int n;
    printf("Enter the numvber of elements in the array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements in the array : \n");
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched for : ");
    int k;
    scanf("%d",&k);
    int index = binary_search(arr,0,n-1,k);
    printf("Element found at index : %d",index);
    return 0;
}
