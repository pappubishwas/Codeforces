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
int n,i;
cin>>n;
int a[n],sum=0;
for ( i = 0; i < n; i++)
{
    cin >>a[i];
}

sort(a,a+n);
for ( i = 0; i < n-1; i++)
{
    if(a[i]==a[i+1]){
        sum=1;
        break;
    }
}
if(sum==0)cout<<"YES"<<endl;
else cout<<"NO"<<endl;

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