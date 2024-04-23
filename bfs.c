#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int G[10][10],visited[10],total;

void BFS(int vertex)
{
    int j;
    printf("%d\t",vertex);
    visited[vertex]=1;
    for(j=0;j<total;j++){
        if(!visited[j] && G[vertex][j]==1)
        {
            BFS(j);
        }
    }
}


int main()
{
    int i,j;
    printf("Enter the number of Vertices in the Graph : ");
    scanf("%d",&total);
    printf("\nEnter the adjacency matrix of the graph : \n");
    for(i=0;i<total;i++){
        for(j=0;j<total;j++){
            scanf("%d",&G[i][j]);
        }
    }
    for(i=0;i<total;i++){
        visited[i]=0;
    }
    printf("\nBFS Traversal is \n");
    BFS(0);
        return 0;

}
