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
const int MOD = 1e9 + 7;
int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }
int powerl(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
int ncr[33][33];
void pre()
{
    for (int i = 0; i <= 32; i++)
    {
        ncr[i][0] = 1;
        ncr[i][i] = 1;
        for (int j = 1; j <= i; j++)
        {
            ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
        }
    }
}
int inMod(int a)
{
    return powerl(a, MOD - 2);
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    int res = 0;
     int msb = 63 - __builtin_clzll(n);
    for (int i = 0; i < msb; i++)
    {
        int t = k - i;
        if (t <= 0)
        {
            res += (1LL << i);
        }
        else if (t <= i)
        {
            for (int j = t; j <= i; j++)
            {
                res += ncr[i][j];
            }
            
        }
    }
    if (msb + 1 > k)
    {
        res++;
    }
    cout << res << "\n";
}
int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pre();
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