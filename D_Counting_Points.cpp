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

void Solve()
{
    int n, m, k;
    cin >> n >> m;
    // vector<pair<int, int>> pap(n);
    vector<int> x(n), r(n);
    for (int i = 0; i < n; i++)
        cin >>x[i];
    for (int i = 0; i < n; i++)
        cin >>r[i];
    // auto com = [&](pair<int, int> &a, pair<int, int> &b)
    // {
    //     return (a.first - a.second) < (b.first - b.second);
    // };
    // sort(pap.begin(), pap.end(), com);

    // vector<int> x(n), r(n);
    // for (int i = 0; i < n; i++)
    // {
    //     x[i] = pap[i].first;
    //     r[i] = pap[i].second;
    // }

    int ans = 0;
    int x1 = -INF;
    int j = 0;
    map<int, int> yval;
    for (int i = 0; i < n; i++)
    {
        j = x[i] - r[i];
        // while (x1 <= x[i] + r[i])
        // {
        //     while (j + 1 < n && (x[j + 1] - r[j + 1]) <= x1)
        //     {
        //         j++;
        //     }
        //     int y = 0;
        //     for (int k = i; k <= j; k++)
        //     {
        //         y = max(y, (int)sqrt(r[k] * r[k] - (x[k] - x1) * (x[k] - x1)));
        //     }
        //     ans += 2 * y + 1;
        //     x1++;
        // }
        while (j <= (x[i] + r[i]))
        {
            yval[j] = max(yval[j], (int)sqrt(r[i] * r[i] - (x[i] - j) * (x[i] - j)));
            j++;
        }
    }
    for (auto &it : yval)
    {
        ans += 2 * it.second + 1;
    }
    cout << ans << "\n";
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