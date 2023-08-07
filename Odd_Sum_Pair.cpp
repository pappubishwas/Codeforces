#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
ll a,b,c;
cin>>a>>b>>c;
if((a%2==0 && b%2==0 && c%2==0) || (a%2==1 && b%2==1 && c%2==1)) cout<<"NO"<<endl;
else cout<<"YES"<<endl;
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