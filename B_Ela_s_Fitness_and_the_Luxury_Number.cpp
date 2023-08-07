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
ld n,k,i,c=0,p;
cin>>n,k;
//ld a[10000];
for(i=n;i<=k;i++){
    p=sqrt(i);
    if(i%==0) c++;
}
cout<<c<<endl;
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