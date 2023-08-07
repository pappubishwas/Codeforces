#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
ll n,x=0,y=0;
cin>>n;
string p;
cin>>p;
for (int i = 0; i < n; i++)
{
    if(p[i]=='U')y++;
    if(p[i]=='R')x++;
    if(p[i]=='D')y--;
    if(p[i]=='L')x--;

    if(x==1 && y==1)
    break;
}
    if(x==1 && y==1) cout<<"YES"<<endl;
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