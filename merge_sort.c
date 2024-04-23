#include<stdio.h>

void merge(int arr[],int left,int mid,int right)
{
    int i,j,k;
    int n1 = mid-left+1;
    int n2 = right-mid;
    int L[n1],R[n2];
    for(i=0;i<n1;i++){
        L[i]=arr[left+i];
    }
    for(j=0;j<n2;j++){
        R[j]=arr[mid+j+1];
    }
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

void merge_sort(int left, int right, int arr[])
{
    if(left<right){
        int mid  = left + (right-left)/2;
        merge_sort(left,mid,arr);
        merge_sort(mid+1,right,arr);
        merge(arr,left,mid,right);
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
    merge_sort(0,n-1,arr);
    printf("\nAfter Sorting : ");
    for(i=0;i<n;i++){
        printf("%d \t",arr[i]);
    }
    return 0;
}
