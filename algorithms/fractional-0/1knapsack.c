#include<stdio.h>

void  main(){
    void aread(int arr[],int n);
    void awrite(float arr[],int n);
    void knapsack(int p[], int w[], int m, int n, float x[], float *tp);
    int p[20],w[20],n,m;
    float tp,x[20];

    printf("enter number of items : ");
    scanf("%d",&n);
    printf("enter weight of item vector in decreasing order od profit per unit weight : ");
    aread(w,n);
    printf("enter profit of items according to their respective weight : ");
    aread(p,n);
    printf("enter capacity of bag: ");
    scanf("%d",&m);
    knapsack(p,w,m,n,x,&tp);
    awrite(x,n);
    printf("Total profit : %0.2hgf",tp);
}

void aread(int arr[],int n){
    for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]);
}

void awrite(float arr[], int n){
    for(int i=1;i<=n;i++)
        printf("%0.2f\t",arr[i]);
    printf("\n");
}

//p[], w[] are profit vector and weight vector respectively and are given 
//in decreasing order of p[]/w[] (profit per unit weight)
void knapsack(int p[], int w[], int m, int n, float x[], float *tp){
    int i;
    float u;
    for(i=1;i<=n;i++)
        x[i] = 0;
    *tp = 0; // total profit
    u = m; //remaining weight
    for(i=1;i<=n;i++){
        if(u>=w[i]){
            x[i] = 1;
            u = u - w[i];
            *tp = *tp + p[i];
        }
        else 
            break;
    }
    if(i<=n){
        x[i] = u/w[i];
        *tp += (p[i]*x[i]);
    }
}