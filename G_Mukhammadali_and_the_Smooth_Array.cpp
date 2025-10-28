#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long 
#define INF (int)1e18
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }

int binaryLength(int n)
{
    return 64 - __builtin_clzll(n);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n); 
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<int> c(n); 
    int total = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> c[i];
        total += c[i];
    }

    vector<int> dp(n, 0);
    int mxsave = 0;

    for (int i = 0; i < n; ++i)
    {
        int prev = 0;
        for (int j = 0; j < i; ++j)
        {
            if (a[j] <= a[i])
            {
                prev = max(prev, dp[j]);
            }
        }

        dp[i] = c[i] + prev;

        mxsave = max(mxsave, dp[i]);
    }

    cout << total - mxsave << "\n";
}

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
