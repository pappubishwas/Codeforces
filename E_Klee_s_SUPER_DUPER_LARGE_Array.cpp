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
    cin >> n >> k;  // i^2 + i*(2k+1) + (2k - n*k - (n-1)*n/2) minimize this eqaution
    int c = 2LL * k - n * k - ((n - 1LL) * (n)) / 2LL;
    int b = 2LL * k + 1LL;
    long double d = (long double)b * (long double)b - 4.0L * (long double)c;
    long double sq = sqrtl(d);
    long double root=(-(long double)b + sq)/2.0L;
    int r1 = (int)floorl(root);
    int ans1 = abs(r1 * r1 + r1 * b + c);
    int ans2 = abs((r1 + 1LL) * (r1 + 1LL) + (r1 + 1LL) * b + c);
    cout << min(ans1, ans2) << endl;
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