#include<stdio.h>

void main()
{
	void bfs(int graph[10][10],int v, int n,int vis[]);
	void gread(int graph[10][10],int *n,int *m);
	void gwrite(int graph[10][10], int n);
	int graph[10][10],n,m,visited[10],v;

	gread(graph,&n,&m);
	gwrite(graph,n);
	for(int i=1;i<=n;i++)
		visited[i] = 0;
	printf("Start vertex : ");
	scanf("%d",&v);
	printf("\nBFS : ");
	bfs(graph,v,n,visited);
}

void bfs(int graph[10][10],int v, int n,int vis[])
{
	void enqueue(int q[], int *front, int *rear, int ele);
	int dequeue(int q[], int *front, int *rear);
	int q[10],w,u,front,rear;

	front = rear = 0;
	printf("%d",v);
	vis[v] = 1;
	u = v;
	while(1)
	{
		//for all vertices w adjacent to u
		for(int w=1;w<=n;w++)
			if(graph[u][w] == 1)
				if(vis[w] == 0)
				{
					printf("%d",w);
					vis[w] = 1;
					enqueue(q,&front,&rear,w);
				}
		//if queue empty bfs done
		if(rear == 0)
			break;
		else 
			u = dequeue(q,&front,&rear);

	}
}

void enqueue(int q[], int *front, int *rear, int ele)
{
	if(*rear == 0)
		*front += 1;
	*rear += 1;
	q[*rear] = ele;
}

int dequeue(int q[], int *front, int *rear)
{
	int ele = q[*front];
	if(*front == *rear)
		*front = *rear = 0;
	else
		*front += 1;
	return ele;
}

void gread(int graph[10][10],int *n,int *m)
{
	int p,q,j;
	printf("Enter  no. of vertices");
	scanf("%d",n);
	//initializing adjacency matrix
	for(int i=1;i<=*n;i++)
		for(j=1;j<=*n;j++)
			graph[i][j] = 0;
			
	//taking edges from user and entering in matrix	
    for(int i=1;i<=*n;i++)
    {
		printf("Enter the edges adjacent to %d",i);
		scanf("%d",&j);
		while(j != -1)
		{
			graph[i][j] = graph[j][i] = 1;
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