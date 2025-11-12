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
    int n, m, x, k;
    cin >> n;
    vector<int> pap(n + 1);
    int blen = binaryLength(n);
    if (n % 2 || n <= 6)
    {
        if (n == 6)
            cout << 7 << endl;
        else
            cout << n << endl;
        pap[n] = n;
        pap[n - 1] = n - 1;
        pap[n - 2] = 3;
        pap[n - 3] = 1;
        int idx = 1;
        for (int i = 1; i <= n; i++)
        {
            if (i == 1 || i == 3 || i == n || i == n - 1)
                continue;
            pap[idx] = i;
            idx++;
        }
    }
    else
    {
        cout << (1 << blen) - 1 << endl;
        int val = (1 << (blen - 1)) - 1;
        pap[n] = n;
        pap[n - 1] = val;
        pap[n - 2] = val - 1;
        pap[n - 3] = 3;
        pap[n - 4] = 1;
        int idx = 1;
        for (int i = 1; i <= n; i++)
        {
            if (i == 1 || i == 3 || i == n || i == val - 1 || i == val)
                continue;
            pap[idx] = i;
            idx++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << pap[i] << " ";
    }
    cout << endl;
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