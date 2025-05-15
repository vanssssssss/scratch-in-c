#include<stdio.h>

int arr[20];

void main(){
    void aread(int *n);
    void awrite(int n);
    void qs(int low,int high);
    int n;

    aread(&n);
    qs(1,n);
    printf("\nSorted array : ");
    awrite(n);
}


void aread(int *n){
    printf("Enter elements in array: ");
    scanf("%d",n);
    for(int i=1;i<=*n;i++)
        scanf("%d",&arr[i]);
}

void awrite(int n){
    for(int i=1;i<=n;i++)
        printf("%d\t",arr[i]);
}

void qs(int low,int high){
    int partition(int low, int high);
    int j;

    if(low <= high){
        j = partition(low,high);
        qs(low,j-1);
        qs(j+1,high);
    }
}

int partition(int low, int high){
    void swap(int *x,int *y);
    int i,j,pivot;
    i = low-1;
    pivot = arr[high];
    for(j=low;j<=high;j++){
        if(arr[j]<pivot)
            swap(&arr[j],&arr[++i]);
    }
    swap(&arr[++i],&arr[high]);
    return i;
}

void swap(int *x,int *y){
    int t = *x;
    *x=*y;
    *y=t;
}