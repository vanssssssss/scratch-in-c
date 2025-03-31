#include<stdio.h>

void main(){
    void gread(int graph[10][10],int *n);
    void gwrite(int graph[10][10], int n);
    void matwrite(int mat[10][10],int n);
    void fw(int cost[10][10], int n, int dis[10][10],int pr[10][10]);
    int cost[10][10],n,dis[10][10],pr[10][10];

    gread(cost,&n);
    gwrite(cost,n);
    fw(cost,n,dis,pr);
}

void fw(int cost[10][10], int n, int dis[10][10],int pr[10][10]){
    void matwrite(int mat[10][10],int n);
    int i,j,k;

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            dis[i][j] = cost[i][j];
            if(i == j)
                dis[i][j] = 0;
                
            if(cost[i][j] == 9999)
                pr[i][j] = -1;
            else
                pr[i][j] = i;
        }
    }

    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++){
                if(dis[i][j] > dis[i][k] + dis[k][j]){
                    pr[i][j] = pr[k][j];
                    dis[i][j] =dis[i][k]+dis[k][j];
                }
            }
        printf("D%d : \n",k);
        matwrite(dis,n);
        printf("P%d : \n",k);
        matwrite(pr,n);
        printf("\n");
    }
}

void matwrite(int mat[10][10],int n){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            printf("%d\t",mat[i][j]);
        printf("\n\n");
    }
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
			graph[i][j] = wt;
			scanf("%d",&j);            
		}
	}
}

void gwrite(int graph[10][10], int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++){
            if(graph[i][j] == 9999)
                printf("nil\t");
            else
			    printf("%d\t",graph[i][j]);
        }
		printf("\n");
	}
}