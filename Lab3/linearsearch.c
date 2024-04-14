#include<stdio.h>
#include<time.h>

int main(){
    clock_t start,end;
    double cpu_time_used;
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=rand();
    }
    printf("Elements : ");
    for(int i=0;i<n;i++){
        printf(" %d ",a[i]);
    }
    printf("element to be searched : ");
    int x;
    int flag=-1;
    scanf("%d",&x);
    start=clock();
    for(int i=0;i<n;i++){
        if(a[i]==x){
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("present");
    }
    else{
        printf("Not present");
    }
    end=clock();
    cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken = %f",cpu_time_used);
    return 0;
}
