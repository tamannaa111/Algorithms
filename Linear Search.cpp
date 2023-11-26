#include<stdio.h>
int main()
{
    int n,i,key,B;
    int sum=0;
    printf("Size :");
    scanf("%d ",&n);

    int A[n];
    for(i=0; i<n; i++)
    {
        scanf("%d",&A[i]);
    }

    scanf("%d",&key);
    for(i=0; i<n; i++)
    {
        if(A[i]==key)
        {
            sum=1;
            break;
        }
    }

    if(sum==1)
    {
        printf("element Found at %d",i);
    }
    else
    {
        printf("element NOT Found ");
    }
}
