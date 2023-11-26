#include<stdio.h>
int main()
{
    int n,i,key,high,low,mid;
    printf("Size :");
    scanf("%d",&n);
    int A[n];
    for(i=0; i<n; i++)
    {
        scanf("%d",&A[i]);
    }
    scanf("%d",&key);
        low=0;
        high=n-1;

    for(i=0; i<n; i++)
    {
        mid=(low+high)/2;
        if(A[mid]<key)
        {
            low=mid+1;
        }
        else if(A[mid]==key)
        {
            printf("element found %d",mid);
            break;
        }
        else
        {
            high=mid-1;
        }
    }
    if(low>high)
    {
        printf("element NOT found ");
    }

}
