#include<stdio.h>

void main(){
    void aread(int arr[],int n);
    void mwrite(int arr[20][30], int n,int m);
    void dknap(int p[],int w[], int n,int m, int t[20][30]);
    void awrite(int arr[], int n);
    void sol(int p[], int w[], int n, int m, int t[20][30], int x[]);
    int p[20],w[20],n,m,x[20],t[20][30];


    printf("enter number of items : ");
    scanf("%d",&n);
    printf("enter weight of item vector  : ");
    aread(w,n);
    printf("enter profit of items according to their respective weight : ");
    aread(p,n);
    printf("enter capacity of bag: ");
    scanf("%d",&m);
    dknap(p,w,n,m,t);
    mwrite(t,n,m);
    sol(p,w,n,m,t,x);
    printf("Solution vector : ");
    awrite(x,n);
    printf("Maximum profit : %d",t[n][m]);
}

void aread(int arr[],int n){
    for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]);
}

void awrite(int arr[], int n){
    for(int i=1;i<=n;i++)
        printf("%d\t",arr[i]);
    printf("\n");
}

void mwrite(int arr[20][30], int n,int m){
    int i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++)
                printf("%d\t",arr[i][j]);
        printf("\n");
    }
}

void dknap(int p[],int w[], int n,int m, int t[20][30]){
    int max(int a, int b);
    int i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            if((i==0)||(j==0))
                t[i][j] =0;
            else
                if(w[i] <= j)
                    t[i][j] = max(t[i-1][j],t[i-1][j-w[i]] + p[i]);
                else
                    t[i][j] =  t[i-1][j];
        }
    }
}

int max(int a, int b){
    if(a>b)
        return a;
    return b;
}

void sol(int p[], int w[], int n, int m, int t[20][30], int x[]){
    int i,j;
    j = m;
    for(i=n;i>0;i--){
        if(t[i][j] == t[i-1][j])
            x[i] = 0;
        else{
            x[i] = 1;
            j = j-w[i];
        }
    }
}