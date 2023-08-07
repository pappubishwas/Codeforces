#include <bits/stdc++.h>
#include<cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
ll n,x,y;
cin>>n;
if(n%2!=0)cout<<"-1"<<endl;
else cout<<1<<" "<<n/2<<endl;

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