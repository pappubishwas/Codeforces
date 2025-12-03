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
int mod = 998244353;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<int> dp(n, n);
    vector<vector<int>> lastSeen(n, vector<int>(26, -1));
    lastSeen[n-1][s[n - 1] - 'a'] = n - 1;
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < k; j++)
        {
            if (lastSeen[i+1][j] != -1)
            {
                dp[i] = min(dp[i], dp[lastSeen[i+1][j]] + 1);
            }
            else
            {
                dp[i] = 1;
            }
            lastSeen[i][j] = lastSeen[i + 1][j];
        }
        lastSeen[i][s[i] - 'a'] = i;
        //cout<< dp[i] << " ";
    }
    for (int i = 0; i < q; i++)
    {
        string t;
        cin >> t;
        int m = t.size();
        int j = 0;
        int idx = 0;
        while (j < m && idx < n)
        {
            int nexPos = lastSeen[idx][t[j] - 'a'];
            if (nexPos == -1)
            {
                idx = n;
                break;
            }
            else
            {
                idx = nexPos;
            }
            idx++;
            j++;
        }
        if (idx == n)
        {
            cout << (j == m) << endl;
        }
        else
        {
            cout << dp[idx - 1] << endl;
        }
    }
}

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    // cin >> t;

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