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

void solve() {
    int n;
    cin >> n;

    vector<int> p(n), pref(n), suff(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    pref[0] = p[0];
    for (int i = 1; i < n; ++i)
        pref[i] = min(pref[i - 1], p[i]); // min value till ith index

    suff[n - 1] = p[n - 1];
    for (int i = n - 2; i >= 0; --i)
        suff[i] = max(suff[i + 1], p[i]); // max value till i th index from backword

    for (int i = 0; i < n - 1; ++i) {
        if (pref[i] > suff[i + 1]) { // that mean there is no way to connect between 0-i th index and i+1 to n index, they will be in different group
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
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