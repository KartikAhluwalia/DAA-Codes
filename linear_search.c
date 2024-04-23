#include<stdio.h>

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
    int flag = -1,index = -1;
    for(i=0;i<n;i++){
        if(arr[i]==k){
            flag=1;
            index = i;
        }
    }
    if(flag==1){
        printf("Element found at index %d",index);
    }
    else{
        printf("Not found");
    }
    return 0;
}
