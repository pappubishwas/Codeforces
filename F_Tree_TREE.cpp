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

int n, k;
vector<vector<int>> adj;
vector<int> subtree;
int total;

int dfs(int u, int p) {
    subtree[u] = 1; 

    for (int v : adj[u]) {
        if (v == p) continue; 
        int vsubtree = dfs(v, u);

        int s_v = vsubtree;
        int s_u = n - vsubtree;

        if (s_u >= k) {
            total += s_v;
        }

        if (s_v >= k) {
            total += s_u;
        }

        subtree[u] += vsubtree;
    }

    return subtree[u];
}

void solve() {
    cin >> n >> k;

    adj.assign(n + 1, vector<int>());
    subtree.assign(n + 1, 0);
    total = 0;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n >= k) {
        total = n;
    }

    dfs(1, -1);

    cout << total << "\n";
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
