//maxmin using divide and conquer
#include<stdio.h>

int arr[20];

void main(){
    void aread(int *n);
    void maxmin(int low, int high, int *max, int *min);
    int n,max,min;

    aread(&n);
    maxmin(1,n,&max,&min);
    printf("Max : %d\nMin : %d",max,min);
}

void aread(int *n){
    printf("Enter elements in array: ");
    scanf("%d",n);
    for(int i=1;i<=*n;i++)
        scanf("%d",&arr[i]);
}

void maxmin(int low, int high, int *max, int *min){
    int mid,max1,min1;
    if(low == high)
        *max = *min = arr[low];
    else if(low+1 == high){
        if(arr[low] > arr[high]){
            *max = arr[low];
            *min = arr[high];
        }
        else{
            *min = arr[low];
            *max = arr[high];
        }
    }
    else{
        mid = (low+high)/2;
        maxmin(low,mid,max,min);
        maxmin(mid+1,high,&max1,&min1);
        if(max1 > *max)
            *max = max1;
        if(min1 < *min)
            *min = min1;
    }
}
