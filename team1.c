#include<stdio.h>
void solve()
{
    
    int i, n,c, k = 0,t=0;
    scanf("%d",&n);
    char p[150][30];
    for (i = 0; i < n; i++)
    {
        scanf("%s[^\n]",p[i]);
    }
    for (i = 0; i < n; i++)
    {
        c=1;
        for (int j = i+1; j < n; j++)
        {
            if (p[i][0] == p[j][0])
                c++;
        }
        if (c >= 3)
        {
            printf("%c\n",p[i][0]);
            t=1;
        }
    }
    if (t==0)
        printf( "impossible");

}
int main()
{
int t;
scanf("%d",&t);
    while (t--)
    {
        solve();
    }
    return 0;
}