#include<stdio.h>

int parents[20];

void main()
{
    void munion(int i, int j);
    int find(int i);
    int n,ch,i,j,p,q;

    printf("Enter no. of elements in set : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        parents[i] = -1;     //parents[i]= -1 , i is a disjoint 
    
    do{
        printf("\nEnter choice : \n1.Union \n2.Find\n3.display parent array\n4.Exit");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter elements for union: ");
                scanf("%d%d",&i,&j);
                p = find(i);
                q = find(j);
                if(p != q) //union can be performed of two disjoint only
                    munion(p,q);
                break;
            case 2:
                printf("\nEnter elements to find representative of: ");
                scanf("%d",&i);
                printf("\nRepresentative of %d is : %d",i,find(i));
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

void munion(int i, int j){ //making i parent of j
    parents[j] = i;
}

int find(int i){ //returns representative of set to which i belongs
    int k;
    k=i;
    while(parents[k] != -1){
        k = parents[k];
    }
    return k;
}