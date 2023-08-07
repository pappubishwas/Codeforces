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
int n,m;
cin>>n>>m;
if((n==2 && m==3)||(n==3 && m==3)||(n==3 && m==2))
cout<<"2 "<<"2 "<<endl;
else
cout<<n<<" "<<m<<endl;

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