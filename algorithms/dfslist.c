#include<stdio.h>
#include<stdlib.h>

typedef struct nd
{
	int data;
	struct nd *next;
}node;

void main()
{
	void read(node *head[], int *n);
	void gwrite(node *head[], int n);
    void dfs(node *graph[],int v,int visited[]);
	node* create(int data);
	node *head[10];
	int n,visited[10],v;;

	read(head,&n);
	gwrite(head,n);
    for(int i=1;i<=n;i++)
		visited[i] = 0;
	printf("Start vertex : ");
	scanf("%d",&v);
	printf("\nDFS : ");
    dfs(head,v,visited);
}

void dfs(node *graph[],int v,int visited[])
{
	int w;
	printf("%d",v);
	visited[v] = 1;
    node *temp = graph[v];
	while(temp)
    {
        w = temp->data;
        if(visited[w] == 0)
            dfs(graph,w,visited);
        temp = temp->next;
    }
}


void read(node *head[], int *n)
{
	node* create(int data);
	int j;

	printf("Enter  no. of vertices ");
	scanf("%d",n);

	for(int i=1;i<=*n;i++)
		head[i] = NULL;
		
	for(int i=1;i<=*n;i++)
	{
		printf("Enter the edges adjacent to %d : ",i);
		scanf("%d",&j);
		while(j != -1)
		{
			node *nn = create(j);
			nn->next = head[i];
			head[i] = nn;

			node *nn1 = create(i);
			nn1->next = head[j];
			head[j] = nn1;
			scanf("%d",&j);
		}
	}
}

void gwrite(node *head[], int n)
{
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
	{
		node *temp = head[i];
		printf("vertex %d ->\t",i);
		while(temp != NULL)
		{
			printf("%d->\t",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

node* create(int data)
{
	node *nn = (node *)malloc(sizeof(node));
	nn->data = data;
	nn->next = NULL;
	return nn;
}
