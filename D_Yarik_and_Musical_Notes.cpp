#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    ll n, res = 0;
    cin >> n;
    vector<ll> ans(n);
    unordered_map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> ans[i];
        mp[ans[i]]++;
    }
    for (auto p : mp)
    {
        ll t = p.second;
        res += (t * (t - 1) / 2);
    }
    res += (mp[1] * mp[2]);
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