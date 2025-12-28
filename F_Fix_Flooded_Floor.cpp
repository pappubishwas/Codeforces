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
const int mod = 998244353;
const int MOD = 1e9 + 7;
int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }
int fact[200001];
int powerl(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int inMod(int a)
{
    return powerl(a, mod - 2);
}
int dp[200005][4];
int sol(int idx, int dir, int r, int n, vector<string> &g)
{
    if (idx == n)
        return 1;
    int key = dir * 2 + r;
    if (dp[idx][key] != -1)
        return dp[idx][key];
    int res = 0;
    if (g[0][idx] == '#' && g[1][idx] == '#')
    {
        res += sol(idx + 1, 0, 0, n, g);
    }
    if (g[0][idx] == '.' && g[1][idx] == '.')
    {
        res += sol(idx + 1, 0, 0, n, g);
    }
    if (idx + 1 < n && g[0][idx] == '.' && g[0][idx + 1] == '.')
    {
        g[0][idx] = '#';
        g[0][idx + 1] = '#';
        res += sol(idx, 0, 1, n, g);
        g[0][idx] = '.';
        g[0][idx + 1] = '.';
    }
    if (idx + 1 < n && g[1][idx] == '.' && g[1][idx + 1] == '.')
    {
        g[1][idx] = '#';
        g[1][idx + 1] = '#';
        res += sol(idx, 1, 1, n, g);
        g[1][idx] = '.';
        g[1][idx + 1] = '.';
    }
    if (g[0][idx] == '.' && g[1][idx] == '#' && idx + 1 < n && g[0][idx + 1] == '#')
    {
        return 0;
    }
    if (g[1][idx] == '.' && g[1][idx] == '#' && idx + 1 < n && g[1][idx + 1] == '#')
    {
        return 0;
    }
    return dp[idx][key] = res;
}

void Solve()
{
    int n;
    cin >> n;
    vector<string> g(2);
    for (int i = 0; i < 2; i++)
    {
        cin >> g[i];
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = -1;
    }
    int ans = sol(0, 0, 0, n, g);
    if (ans == 0)
    {
        cout << "None\n";
    }
    else if (ans == 1)
    {
        cout << "Unique\n";
    }
    else
    {
        cout << "Multiple\n";
    }
}
int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    return 0;
}