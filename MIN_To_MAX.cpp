#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve()
{
int n,min,i;
cin>>n;
int a[n];
for ( i=0;i<n;i++)
cin>>a[i];
sort(a,a+n);
min=a[0];
for( i=1;i<n;i++)
if(min<a[i])
break;

cout<<n-i<<endl;
}

int main()
{
    long long tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}


