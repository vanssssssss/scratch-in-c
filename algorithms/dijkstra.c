#include<stdio.h>

void main(){
    void gread(int graph[10][10],int *n);
    void gwrite(int graph[10][10], int n);
	void dijkstra(int cost[10][10],int n, int v, int dis[]);
    int cost[10][10],n,v,dis[10];

    gread(cost,&n);
    gwrite(cost,n);
	printf("\nEnter source vertex : ");
	scanf("%d",&v);
	dijkstra(cost,n,v,dis);
	for(int i=1;i<=n;i++)
		printf("%d\t",dis[i]);
}

void dijkstra(int cost[10][10],int n, int v, int dis[]){
	int minc(int dis[10],int n, int s[10]);
	int i,s[10],u,w;
	for(i=1;i<=n;i++){
		s[i] = 0;
		dis[i] = cost[v][i];
	}
	s[v] = 1;
	dis[v] = 0;
	for(i=1;i<n;i++){
		u = minc(dis,n,s);
		s[u] = 1;
		for(w=1;w<=n;w++)
			if(cost[u][w] != 9999)
				if(s[w] == 0)
					if(dis[w] > dis[u]+cost[u][w])
						dis[w] = dis[u]+cost[u][w];
	}
}

int minc(int dis[10],int n, int s[10]){
	int min,i,j;
	min = __INT_MAX__;
	for(i=1;i<=n;i++)
		if(s[i] == 0)
			if(dis[i] < min){
				min = dis[i];
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