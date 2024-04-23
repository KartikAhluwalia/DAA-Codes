#include<stdio.h>
#include<time.h>

int main()
{
    int m,n;
    int r = 0;
    printf("Enter the numbers : ");
    scanf("%d %d",&m,&n);
    while(n!=0){
        r = m%n;
        m=n;
        n=r;
    }
    printf("GCD is %d ",m);
    return 0;
}
