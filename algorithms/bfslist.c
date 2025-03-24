#include<stdio.h>
#include<stdlib.h>

typedef struct nd
{
	int data;
	struct nd *next;
}node;

void main()
{
    void bfs(node *graph[],int v, int n,int vis[]);
	void read(node *head[], int *n);
	void gwrite(node *head[], int n);
	node* create(int data);
	node *graph[10];
	int n,m,visited[10],v;

	read(graph,&n);
	gwrite(graph,n);
    for(int i=1;i<=n;i++)
		visited[i] = 0;
	printf("Start vertex : ");
	scanf("%d",&v);
	printf("\nBFS : ");
	bfs(graph,v,n,visited);
}

void bfs(node *graph[],int v, int n,int vis[])
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
		node *temp = graph[u];
        while(temp != NULL)
        {
            w = temp->data;
			if(vis[w] == 0)
			{
				printf("%d",w);
				vis[w] = 1;
				enqueue(q,&front,&rear,w);
			}
            temp = temp->next;
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