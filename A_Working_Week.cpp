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
ll n,t;
double p;
cin>>n;
t=(n-4)/3;
p=(double)(n-4)/3;
if(p>(t+0.5))
cout<<t<<endl;
else
cout<<t-1<<endl;

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