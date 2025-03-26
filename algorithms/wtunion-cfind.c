#include<stdio.h>

int parents[20];

void main()
{
    void wtunion(int i, int j);
    int cfind(int i);
    int n,ch,i,j,p,q;

    printf("Enter no. of elements in set : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        parents[i] = -1;     //parents[i]= -1 , i is a disjoint 
    
    do{
        printf("\nEnter choice : \n1.Weighted Union \n2.Collapsing Find\n3.display parent array\n4.Exit");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter elements for union: ");
                scanf("%d%d",&i,&j);
                p = cfind(i);
                q = cfind(j);
                if(p != q) //union can be performed of two disjoint only
                    wtunion(p,q);
                break;
            case 2:
                printf("Enter elements to find representative of: ");
                scanf("%d",&i);
                printf("Representative of %d is : %d",i,cfind(i));
                break;
            case 3:
                for(int i=1;i<=n;i++)
                    printf("%d\t",parents[i]);
                break;
            case 4:
                break;
            default:
                printf("Choice doesn't exit");
        }
    }while(ch != 4);
}

void wtunion(int i, int j){ //making which disjoint as more element as paremt
    int count = 0;
    count = parents[i] + parents[j];
    if(parents[i] < j){
        parents[j] = i;
        parents[i] = count;
    }
    else{
        parents[i] = j;
        parents[j] = count;
    }
}

int cfind(int i){ //returns representative of set to which i belongs
    int k,j,t;
    k=i;
    while(parents[k] > 0){
        k = parents[k];
    }
    j=i;
    while(j != k){
        t = j;
        j = parents[j];
        parents[t] = k;
    }
    return k;
}