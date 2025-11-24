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
    cin >> n;
    vector<pair<int, int>> pap(n);
    set<pair<int, int>> uset;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        pap[i] = {x, y};
        uset.insert({x, y});
    }
    int count = 0;
    sort(pap.begin(), pap.end());
    for (int i = 0; i < n - 1; i++)
    {
        if (pap[i].first == pap[i + 1].first)
        {
            count += (n - 2);
        }
        if (pap[i].second==0 && uset.find({pap[i].first + 1, pap[i].second + 1}) != uset.end() && uset.find({pap[i].first + 2, pap[i].second}) != uset.end())
        {
            count++;
        }
        if (pap[i].second==1 && uset.find({pap[i].first + 2, pap[i].second}) != uset.end() && uset.find({pap[i].first + 1, pap[i].second-1}) != uset.end())
        {
            count++;
        }
    }
    cout << count << endl;
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