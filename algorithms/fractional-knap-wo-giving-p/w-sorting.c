#include<stdio.h>

void  main(){
    void aread(int arr[],int n);
    void awrite(float arr[],int n);
    void knapsack(int p[], int w[], int m, int n, int s[], float x[], float *tp);
    void sort(float arr1[], int arr2[], int n);
    int p[20],w[20],n,m;
    float pw[20],cpw[20];
    int s[20];
    float tp,x[20];

    printf("enter number of items : ");
    scanf("%d",&n);
    printf("enter weight of item vector : ");
    aread(w,n);
    printf("enter profit of items according to their respective weight : ");
    aread(p,n);
    printf("enter capacity of bag: ");
    scanf("%d",&m);

    for(int i=1;i<=n;i++){
        pw[i] = (p[i]*1.0)/w[i];
        cpw[i] = pw[i];
        s[i] = i;
    }
    sort(cpw,s,n);
    // awrite(pw,n);
    // awrite(cpw,n);
    // awrite(s,n);
    knapsack(p,w,m,n,s,x,&tp);
    awrite(x,n);
    printf("Total profit : %0.2f",tp);
}

void sort(float arr1[], int arr2[], int n){
    void swap(float *x,float *y);
    void swapi(int *x,int *y);
    int i,j;
    for(i=1;i<n;i++){
        for(j=1;j<=n-i;j++){
            if(arr1[j] < arr1[j+1]){
                swap(&arr1[j],&arr1[j+1]);
                swapi(&arr2[j],&arr2[j+1]);
            }
        }
    }
}

void swap(float *x,float *y){
    float t = *x;
    *x=*y;
    *y=t;
}

void swapi(int *x,int *y){
    int t = *x;
    *x=*y;
    *y=t;
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
void knapsack(int p[], int w[], int m, int n,int s[], float x[], float *tp){
    int i;
    float u;
    for(i=1;i<=n;i++)
        x[i] = 0;
    *tp = 0; // total profit
    u = m; //remaining weight
    for(i=1;i<=n;i++){
        if(u>=w[s[i]]){
            x[s[i]] = 1;
            u = u - w[s[i]];
            *tp = *tp + p[s[i]];
        }
        else 
            break;
    }
    if(i<=n){
        x[s[i]] = u/w[s[i]];
        *tp += (p[s[i]]*x[s[i]]);
    }
}