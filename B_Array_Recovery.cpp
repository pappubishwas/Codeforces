#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include <numeric>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
int d[100],a[100],i,d1,p=0,n;
cin>>n;
for(i=0;i<n;i++){
    cin>>d[i];
}
a[0]=d[0];
for ( i = 2; i <= n; i++)
{
    a[i-1]=a[i-2]+d[i-1];
    d1=a[i-2]-d[i-1];
    if(d1>=0 && a[i-1]>=0 && (d1!=a[i-1])){
        cout<<"-1"<<endl;
        p++;
        break;
    }
}
if(p==0){
for(i=0;i<n;i++){
    cout<<a[i]<<" ";
}
cout<<endl;   
}

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}