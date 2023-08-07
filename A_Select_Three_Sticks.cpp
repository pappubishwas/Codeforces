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
int n,c,i,min;
cin>>n;
int a[n];
for(i=0;i<n;i++)cin>>a[i];
sort(a,a+n);
min=a[2]-a[0];
for(i=0;i<n-2;i++){
    c=a[i+2]-a[i];
    if(c<=min) min=c;
}
cout<<min<<endl;
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