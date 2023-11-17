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
    for (ll i = 0; i < n; i++)
    {
        cin >> ans[i];
    }
     vector<ll> dp=ans;
    for (ll i = 1; i < n; i++)
    {
        if ((abs(ans[i]) % 2 == 0 && abs( ans[i - 1]) % 2 == 0) || (abs(ans[i]) % 2 == 1 && abs(ans[i - 1]) % 2 == 1))
            continue;
        else
        {
            dp[i] = max(dp[i], (dp[i - 1] + ans[i]));
        }
    }
    
    res = *max_element(dp.begin(), dp.end());
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