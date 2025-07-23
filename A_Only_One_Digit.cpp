#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'


void solve()
{
    ll n, k;
    cin >> n;

    ll res=9;
    while(n > 0)
    {
        ll t=n%10;
        res=min(res, t);
        n /= 10;
    }
    cout << res << endl;

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