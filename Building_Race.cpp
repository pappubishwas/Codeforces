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
float a,b,x,y;
cin>>a>>b>>x>>y;
if((a/x)<(b/y))
    cout<<"Chef"<<endl;
else if((a/x)>(b/y))
cout<<"Chefina"<<endl;
else
cout<<"Both"<<endl;

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