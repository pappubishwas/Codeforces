#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve()
{
int n,i=0,k=0,l=0,m=0,j,p,c=0;
cin>>n;
int a[n],b[n];
for ( i = 0; i < n; i++)
{
    cin>>a[i];
    if(a[i]==1)c++;
}
for ( i = 0; i < n; i++)
{
    cin>>b[i];
}



if (a[0]!=b[0] || a[n-1]!=b[n-1])cout<<"NO"<<endl;
else{
for ( i = 1; i < n-1; i++)
{


if(a[i]!=b[i]){
    if(a[i]==0 && c!=0){
continue;
    }else{ 
k=1;
break;
    }
}
}
if(k==0)cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}
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


