#include<stdio.h>

int arr[20];

void main(){
    void aread(int *n);
    void awrite(int n);
    void mergesort(int low,int high);
    int n;

    aread(&n);
    mergesort(1,n);
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

void merge(int low, int high){
    int mid,i,j,k,temp[20];
    mid = (low+high)/2;
    i = low;
    j = mid+1;
    k = 0;
    while((i<=mid) && (j<=high)){
        if(arr[i] < arr[j])
            temp[++k] = arr[i++];
        else    
            temp[++k] = arr[j++];
    }
    while(i<=mid)
        temp[++k] = arr[i++];
    while(j<=high)
        temp[++k] = arr[j++];

    for(i=low;i<=high;i++)
        arr[i] = temp[i-low+1]; 
}

void mergesort(int low,int high){
    void merge(int low, int high);
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,high); 
    }
}