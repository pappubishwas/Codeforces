#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
   ll n,k;
   cin>> n>>k;
   string s;
   cin>> s;
   int cc = count(s.begin(), s.end(), '1');
   if(k>=cc || n+1<=2*k) cout<<"Alice"<<endl;
   else cout<<"Bob"<<endl;
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