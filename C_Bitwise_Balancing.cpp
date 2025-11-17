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
    int b, c, d;
    cin >> b >> c >> d;
    int a = 0;

    // check bits up to 63
    for (int i = 0; i <= 63; ++i) {
        int bit = (1LL << i);
        bool bb = (b & bit) != 0;
        bool cc = (c & bit) != 0;
        bool dd = (d & bit) != 0;

        // if d has 0 but b has 1 => impossible (OR can't change 1->0)
        if (!dd && bb && !cc) {
            cout << -1 << '\n';
            return;
        }
        // if d has 1, b has 0, but c forbids setting that bit in a => impossible
        if (dd && !bb && cc) {
            cout << -1 << '\n';
            return;
        }
        // if d has 1 and b has 0, we must set that bit in a (and c must be 0 here)
        if (dd && !bb) {
            a |= bit;
        }
        if(!dd && bb && cc)  a |=bit;
    }

    cout << a << '\n';
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