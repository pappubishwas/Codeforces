#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> ans(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> ans[i];
    }
    sort(ans.begin(), ans.end());
    ll minrev = 0, maxrev = 0, max1 = 0, max2 = 0, min1 = 0, min2 = 0;
    int l = k-2, h = n - 1, t = 0;
    while (t < k)
    {
        minrev += ans[l];
        l += (k-2);
        t++;
    }
    l = 1, h = n - 2, t = 0;
    while (t < k)
    {
        maxrev += ans[h];
        h -= 2;
        t++;
    }

    cout <<minrev << " " << maxrev << endl;
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