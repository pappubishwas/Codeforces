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
const int N = 1e5 + 69;
bool sv[N];

void Solve()
{
    int n, r, d, m;
    cin >> n ;
    vector<int> papa(n),papb(n);
    for(int i=0;i<n;i++) cin>>papa[i];
    for(int i=0;i<n;i++) cin>>papb[i];

    int currMax = 0;
    int currMin = 0;

    for (int i = 0; i < n; ++i) {
        int val1 = currMax - papa[i];
        int val2 = papb[i] - currMax;
        int val3 = currMin - papa[i];
        int val4 = papb[i] - currMin;

        currMax = max({val1, val2, val3, val4});
        currMin = min({val1, val2, val3, val4});
    }

    cout << currMax << "\n";
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
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}