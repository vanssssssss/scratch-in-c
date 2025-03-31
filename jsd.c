#include<stdio.h>

void main(){
    void aread(int arr[],int n);
    void awrite(int arr[],int n);
    void sort(int arr1[], int arr2[], int n);
    void jsd(int d[],int s[],int n, int j[], int *k);
    int profit[20],deadline[20],n,job[20],k,profitcopy[20],sorted[20];
    

    printf("enter number of jobs : ");
    scanf("%d",&n);
    printf("enter deadline of jobs vector : ");
    aread(deadline,n);
    printf("enter profit of jobs according to their respective deadline : ");
    aread(profit,n);

    for(int i=1;i<=n;i++){
        profitcopy[i] = profit[i];
        sorted[i] = i;
    }
    sort(profitcopy,sorted,n);
    awrite(profit,n);
    awrite(profitcopy,n);
    jsd(deadline,sorted,n,job,&k);
    awrite(job,k);
}

void jsd(int d[],int s[],int n, int j[], int *k){
    void awrite(int arr[],int n);
    int r;
    d[0] = j[0] = 0;
    j[1] = s[1];
    *k = 1;                 //1st job is always feasible
    for(int i=2;i<=n;i++){
        r = *k;
        //till where shifting is possible
        while(( d[j[r]]>d[s[i]] ) && ( d[j[r]]>r ))
            r -= 1;
        
            //if it is feasible to put job at (r+1)th place
            if(( d[j[r]]<=d[s[i]] ) && ( d[s[i]]>r )){
                //shift
                for(int l=*k;l>=r;l--)
                    j[l+1] = j[l];
                j[r+1] = s[i];
                *k = *k+1;
                awrite(j,*k);
            }
    }
}

void sort(int arr1[], int arr2[], int n){
    void swap(int *x,int *y);
    int i,j;
    for(i=1;i<n;i++){
        for(j=1;j<=n-i;j++){
            if(arr1[j] < arr1[j+1]){
                swap(&arr1[j],&arr1[j+1]);
                swap(&arr2[j],&arr2[j+1]);
            }
        }
    }
}

void swap(int *x,int *y){
    int t = *x;
    *x=*y;
    *y=t;
}

void aread(int arr[],int n){
    for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]);
}

void awrite(int arr[],int n){
    for(int i=1;i<=n;i++)
        printf("%d\t",arr[i]);
    printf("\n");
}