#include<stdio.h>
int graph[10][10] , visited[10],n;
void main()
{
	void gread();
	void gwrite();
	void dfs(int v);
	int v;
	gread();
	gwrite();
	for(int i=1;i<=n;i++)
		visited[i] = 0;
	printf("Enter start vertex : ");
	scanf("%d",&v);
	printf("\nDFS : ");
	dfs(v);
}

void dfs(int v)
{
	int w;
	printf("%d",v);
	visited[v] = 1;
	for(int w=1;w<=n;w++)
		if((graph[v][w] == 1) && (visited[w] == 0))
			dfs(w);
}

void gread()
{
	int p,q,m;
	printf("Enter  no. of vertices");
	scanf("%d",&n);
	printf("Enter no of edges");
	scanf("%d",&m);
	//initializing adjacency matrix
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			graph[i][j] = 0;
			
	//taking edges from user and entering in matrix	
	printf("Enter the edges");
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&p,&q);
		graph[p][q] = graph[q][p] = 1;
	}
}

void gwrite()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d\t",graph[i][j]);
		printf("\n");
	}
}