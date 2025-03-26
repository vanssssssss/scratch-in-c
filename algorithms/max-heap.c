#include<stdio.h>

void main(){
    void heapify(int arr[], int n);
    int n,arr[20];
    printf("Enter elements in array: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    heapify(arr,n);
    printf("Heapify array : ");
    for(int i=1;i<=n;i++)
        printf("%d\t",arr[i]);
}

void adjust(int arr[], int n, int i){
    int x,j;
    x = arr[i];
    j = 2*i;
    while(j<=n){
        if(j<n)
            if(arr[j+1] > arr[j]) //comparing both children
                j= j+1;

        if(arr[j] > x){             //comparing children with parent
            arr[j/2] = arr[j];
            j = 2*j;
        }
        else
            break;
    }
    arr[j/2] = x; 
}

void heapify(int arr[], int n)
{
    void adjust(int arr[], int n, int i);
    for(int i=n/2;i>=1;i--){
        adjust(arr,n,i); //adjusting heap for every node
    }
}