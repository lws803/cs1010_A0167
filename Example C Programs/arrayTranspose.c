#include<stdio.h>
 
int main()
{
    int a[5][5],i,j,m,n;
    
    printf("How many rows?");
    scanf("%d",&n);
    printf("How many columns?");
    scanf("%d",&m);
    
    printf("\nEnter the matrix:\n");
    for(i=0;i<m;++i)
        for(j=0;j<n;++j)
            scanf("%d",&a[i][j]);
            
    printf("\nTranspose of given matrix:\n");
    
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
            printf("%d ",a[j][i]);
        
        printf("\n");
    }
 
    return 0;
}