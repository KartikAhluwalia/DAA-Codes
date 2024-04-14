#include<stdlib.h>
#include<stdio.h>
//Time complexity O(log n)
int main(){
    int x = 0,y=0;
    int rem = 0;
    printf("Please enter the two numbers you want to find the GCD for\n");
    scanf("%d %d",&x,&y);
    while(y!=0){
        rem=x%y;
        x=y;
        y=rem;
    }
    printf("The GCD of the two numbers is %d\n",x);

    return 0;
}
