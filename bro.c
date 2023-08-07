#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n],i,odd=0,even=0;
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for ( i = 0; i < n; i++)
    {
        if(a[i]%2==0)
         even++;
        else
         odd++;
    }
    if (even==0||odd==0)
    {
        printf("Yes\n");
    }
    else
    {
    for ( i = 0; i < n; i=i+2)
    {
        a[i]=a[i]+1;
    }
    even=0;
    odd=0;
    for ( i = 0; i < n; i++)
    {
        if(a[i]%2==0)
         even++;
        else
         odd++;
    }
    if(odd==0||even==0)
      printf("Yes\n");
    else
      printf("No\n");      
    }
    
return 0;
}
