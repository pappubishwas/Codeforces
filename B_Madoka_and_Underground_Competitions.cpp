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
int n,k,r,c;
cin>>n>>k>>r>>c;
int p=r,q=c;
if(r>k)
p=r-k;
if(c>k)
q=c-k;
for (int i = 0; i < n; i++)
{
    if(p=i)
    k++;
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