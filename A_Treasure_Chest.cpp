#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    ll x, y, k;
    cin >> x >> y >> k;
    if (x >= y)
        cout << x << endl;
    else if ((x + k) >= y)
        cout << y << endl;
    else
        cout << (x + k) + (y - x - k) * 2 << endl;
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