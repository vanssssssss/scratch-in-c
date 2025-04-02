#include<stdio.h>
#include<stdlib.h>

int n,x[20],ans;

void main(){
    void Nqueen(int k);
    ans=0;
    printf("enter number of queens : ");
    scanf("%d",&n);
    Nqueen(1);
    printf("total possible solutions  : %d",ans);
}

void Nqueen(int k){
    int place(int k, int i);
    int i;
    for(i=1;i<=n;i++){
        if(place(k,i)){
            x[k] = i;
            if(k==n){
                printf("solution vector : ");
                for(int j=1;j<=k;j++)
                    printf("%d\t",x[j]);
                printf("\n");
                ans++;
            }
            else
                Nqueen(k+1);
        }
    }
}

int place(int k, int i){
    int j,flag;
    flag = 1;
    for(j=1;j<k;j++){
        if((x[j] == i) || (abs(k-j) == abs(i-x[j]))){
            flag = 0;
            break;
        }
    }
//    printf("%d\n",flag);
    return flag;
}