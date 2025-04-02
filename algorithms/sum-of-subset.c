#include<stdio.h>

int w[20],m,x[20];

void main(){
    void aread(int *n);
    void awrite(int n);
    void subsetSum(int s, int k, int r);
    int n,s,r;

    aread(&n);
    awrite(n);
    printf("Enter sum of subset : ");
    scanf("%d",&m);
    s=0;
    r=0;
    for(int i=1;i<=n;i++)
        r+= w[i];
    printf("Solution vector :\n");
    subsetSum(s,1,r);

}

void subsetSum(int s, int k, int r){
    // printf("%d %d %d\n",s,k,r);
    x[k] = 1;
    if(s + w[k] == m){
        for(int i=1;i<=k;i++)
            printf("\t%d",x[i]);
        printf("\n");
    }
    else{
        if(s + w[k] + w[k+1] <= m){
            subsetSum(s+w[k],k+1,r-w[k]);
        }
        if((s+w[k+1] <= m) && (s+r-w[k] >= m)){
            x[k] = 0;
            subsetSum(s,k+1,r-w[k]); 
        }
    }
}

void aread(int *n){
    printf("Enter elements in array: ");
    scanf("%d",n);
    for(int i=1;i<=*n;i++)
        scanf("%d",&w[i]);
}

void awrite(int n){
    for(int i=1;i<=n;i++)
        printf("%d\t",w[i]);
    printf("\n");
}

