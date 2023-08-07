#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
ll n,c=0;
cin>>n;
ll a[n];

for (ll i = 0; i < n; i++)
{
    cin>>a[i];
}
sort(a,a+n);
for (ll i = 0; i < n-1; i++)
{
    if(a[i+1]-a[i]==1) c++;
    else if(a[i+1]-a[i]==0) continue;
    else break;
}
if(c==n-1) cout<<c<<endl;
else if(c>0 ||  a[0]==1)
cout<<c+1<<endl;
else cout<<c<<endl;

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