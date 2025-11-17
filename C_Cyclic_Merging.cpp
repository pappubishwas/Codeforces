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
    int n;
    cin >> n;
    vector<int> pap(n);
    multiset<pair<int, int>> st;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pap[i];
        st.insert({pap[i], i});
        int l = ((i - 1 < 0) ? n - 1 : i - 1);
        int r = ((i + 1 >= n) ?  0 : i + 1);
        adj[i].push_back(l);
        adj[i].push_back(r);
    }
    int res = 0;
    for (auto &it : st)
    {
        int idx = it.second;
        if (n == 1)
        {
            res += (pap[idx]);
            continue;
        }
        if (n == 2)
        {
            n--;
            continue;
        }
        auto v = adj[idx];
        res += min(pap[v[0]], pap[v[1]]);
        adj[v[0]].erase(remove(adj[v[0]].begin(), adj[v[0]].end(), idx), adj[v[0]].end());
        adj[v[1]].erase(remove(adj[v[1]].begin(), adj[v[1]].end(), idx), adj[v[1]].end());

        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
        n--;
    }
    cout << res << endl;
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