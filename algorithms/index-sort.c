#include<stdio.h>

void main(){
    void aread(int arr[],int n);
    void awrite(int arr[],int n);
    void sort(int arr1[], int arr2[], int n);
    int pw[20],cpw[20],n,s[20];

    printf("enter number of items : ");
    scanf("%d",&n);
    aread(pw,n);
    for(int i=1;i<=n;i++){
        cpw[i] = pw[i];
        s[i] = i;
    }
    sort(cpw,s,n);
    awrite(cpw,n);
    awrite(pw,n);
    awrite(s,n);
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

void awrite(int arr[], int n){
    for(int i=1;i<=n;i++)
        printf("%d\t",arr[i]);
    printf("\n");
}