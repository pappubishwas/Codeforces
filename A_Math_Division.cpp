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
// const int mod = 998244353;
const int mod = 1e9 + 7;
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
int dp[200005][2];
int sol(string &s, int carry, int idx, int n)
{
    if (idx == 0)
    {
        return carry;
    }
    if(dp[idx][carry]!=-1) return dp[idx][carry];
    int curr = (s[idx] - '0') + carry;
    int ans = 0;
    int in2 = inMod(2);
    if (curr == 0)
    {
        ans = (1 + sol(s, 0, idx - 1, n)) % mod;
    }
    else if (curr == 1)
    {
        int p1 = sol(s, 0, idx - 1, n);
        int p2 = sol(s, 1, idx - 1, n);
        int avg = (p1 + p2)%mod * in2 % mod;
        ans = (avg + 1) % mod;
    }
    else if (curr == 2)
    {
        ans = (1 + sol(s, 1, idx - 1, n)) % mod;
    }
    return dp[idx][carry] = ans%mod;
}
void Solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    cout << sol(s, 0, n - 1, n) << endl;
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