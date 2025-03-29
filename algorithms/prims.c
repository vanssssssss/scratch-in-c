#include<stdio.h>

void main(){
    void prims(int cost[10][10],int n,int t[10][2],int *mc);
    void gread(int graph[10][10],int *n);
    void gwrite(int graph[10][10], int n);
    int cost[10][10],n,t[10][2],mc;
        
    gread(cost,&n);
    gwrite(cost,n);
    prims(cost,n,t,&mc);
    printf("Edges in minimum spanning tree : ");
    for(int i=1;i<n;i++){
        printf("%d\t%d\n",t[i][1],t[i][2]);
    }
    printf("minimum cost : %d",mc);
}

void prims(int cost[10][10],int n,int t[10][2],int *mc){
    int minc(int cost[10][10], int near[], int n);
    int near[10],i,j,k;
    near[1] = 0;
    for(i=2;i<=n;i++)
        near[i] = 1;
    *mc = 0;
    for(i=1;i<n;i++){
        j = minc(cost,near,n);
        t[i][1] = j;
        t[i][2] = near[j];
        *mc = *mc + cost[j][near[j]];
        near[j] = 0;
        for(k=1;k<=n;k++)
            if(near[k] != 0)
                if(cost[k][near[k]] > cost[k][j])
                    near[k] = j;
    }
}

int minc(int cost[10][10], int near[], int n){
    int i,min,j;
    min = __INT_MAX__;
    for(i=1;i<=n;i++)
        if(near[i] != 0)
            if(cost[i][near[i]] < min){
                min = cost[i][near[i]];
                j = i;
            }
    return j;
}

void gread(int graph[10][10],int *n)
{
	int j,wt;
	printf("Enter  no. of vertices : ");
	scanf("%d",n);
	//initializing adjacency matrix
	for(int i=1;i<=*n;i++)
		for(j=1;j<=*n;j++)
			graph[i][j] = 9999;
			
	//taking edges from user and entering in matrix	
    for(int i=1;i<=*n;i++)
    {
        printf("Enter -1 if their are no adjacent vertices.\n");
		printf("Enter the edges adjacent to %d with their respective weight : ",i);
		scanf("%d",&j);
		while(j != -1)
		{
            scanf("%d",&wt);
			graph[i][j] = graph[j][i] = wt;
			scanf("%d",&j);            
		}
	}
}

void gwrite(int graph[10][10], int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d\t",graph[i][j]);
		printf("\n");
	}
}