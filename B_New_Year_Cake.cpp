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
int sol(int a, int b)
{
    int s = 1LL;
    int flag = true;
    int ans = 0;
    while (a >= 0 && b >= 0)
    {
        if (flag)
        {
            if (a < s)
            {
                break;
            }
            a -= s;
            flag = !flag;
        }
        else
        {
            if (b < s)
            {
                break;
            }
            b -= s;
            flag = !flag;
        }
        ans++;
        s=s*2LL;
    }
    return ans;
}
void Solve()
{
    int a, b;
    cin >> a >> b;
    int ans1 = sol(a, b);
    int ans2 = sol(b, a);
    cout << max(ans1, ans2) << endl;
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