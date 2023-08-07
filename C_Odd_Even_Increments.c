#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n],i,odd=0,even=0,even1=0,odd1=0;
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for ( i = 0; i < n; i=i+2)
    {
        if(a[i]%2==0)
         even++;
        else
          odd++;
    }
    for ( i = 1; i < n; i=i+2)
    {
        if(a[i]%2==0)
         even1++;
        else
          odd1++;
    }
    if ((odd==0 && even1==0)||(even==0 && odd1==0)||((even+even1)==n || (odd+odd1)==n))
    {
        printf("Yes\n");
    }
    else
    printf("No\n");
    
return 0;
}