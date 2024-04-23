#include<stdio.h>

void toh(char src, char aux, char dst, int n)
{
    if(n==0){
        return;
    }
    toh(src,dst,aux,n-1);
    printf("Move disc %d from %c rod to %c rod\n",n,src,dst);
    toh(aux,src,dst,n-1);
}

int main()
{
    int n = 3;
    toh('A','B','C',n);
    return 0;
}
