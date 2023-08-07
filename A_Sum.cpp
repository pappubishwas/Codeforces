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
int a[3];
cin>>a[0]>>a[1]>>a[2];
sort(a,a+3);
int sum=a[0]+a[1];
if(a[2]==sum)cout<<"YES"<<endl;
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