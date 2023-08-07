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
int n,count=0,k,a[50];
cin>>n>>k;
for (int i = 0; i < n; i++)
{
    cin>>a[i];
}
for (int i = 0; i < n; i++)
{
    if(a[i]==1) break;
    else count++;
}
if(count==n) cout<<"NO"<<endl;
else cout<<"YES"<<endl;


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