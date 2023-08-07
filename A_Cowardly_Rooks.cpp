#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
ll n,m,c=0;
cin>>n>>m;
ll a[m],b[n];
for (ll i = 0; i < m; i++)
{
    cin>>a[i]>>b[i];
}
if(m<n) cout<<"YES"<<endl;
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