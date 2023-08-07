#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve()
{
int n,k,i,j,tempk,sum=0,c;
cin>>n>>k;
int a[n];
for (i=0;i<n;i++){
    cin>>a[i];
}
for ( i = 0; i < n; i++)
{
    tempk=k-a[i];
    for ( j = i; j < n; j++)
    {
        sum+=a[j];
        if(sum>tempk)
        break;
        else if(sum==tempk) c++;
    }
    
}

    cout<<c<<endl;
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


