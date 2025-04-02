#include<stdio.h>

int cost[10][10],n,x[10],m;

void main(){
    void gread(int graph[10][10],int *n);
    void gwrite(int graph[10][10], int n);
    void mcoloring(int k);

    gread(cost , &n);
    gwrite(cost, n);
    printf("Enter the number of color : ");
    scanf("%d",&m);
    for(int i=1;i<=n;i++)
        x[i] = 0;
    mcoloring(1);
}

void mcoloring(int k){
    void nextValue(int k);
    while (1)
    {
        nextValue(k);
        if(x[k] == 0)           //no next value of k
            break;
        if(k==n){
            for(int i=1;i<=n;i++)           //solution vector
                printf("%d\t",x[i]);
            printf("\n");
        }
        else
            mcoloring(k+1);
    }
    
}

void nextValue(int k){
    int j;
    while(1){
        x[k] = ((x[k]+1)%(m+1));          //next possible value
        if(x[k] == 0)                   //no next value
            break;     
        for(j=1;j<=k-1;j++)             
            if(cost[j][k] == 1)           //looking for adjacent edges
                if(x[j] == x[k])            //and checking if any of them are of same color
                    break;
        if(j == k)                          //no adjacent edge of k are of same color as k so it x[k] is next value
            break;
    }
}

void gread(int graph[10][10],int *n)
{
	int j;
	printf("Enter  no. of vertices : ");
	scanf("%d",n);
	//initializing adjacency matrix
	for(int i=1;i<=*n;i++)
		for(j=1;j<=*n;j++)
			graph[i][j] = 0;
			
	//taking edges from user and entering in matrix	
    for(int i=1;i<=*n;i++)
    {
        printf("Enter -1 if their are no adjacent vertices.\n");
		printf("Enter the edges adjacent to %d  : ",i);
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