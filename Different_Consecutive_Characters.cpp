#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
ll c=0,n;
string s;
cin >>n;
cin>>s;
for (ll i = 0;i<n-1; i++)
{
    if(s[i]==s[i+1]) c++;
}
cout<<c<<endl;
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