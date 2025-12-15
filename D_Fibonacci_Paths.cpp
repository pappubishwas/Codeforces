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

const int MOD = 998244353;

int dfs(
    int edge_idx,
    vector<int> &a,
    vector<pair<int, int>> &edges,
    vector<vector<pair<int, pair<int, int>>>> &adj,
    vector<int> &dp,
    vector<map<int, int>> &tan)
{
    if (dp[edge_idx] != -1)
        return dp[edge_idx];

    int u = edges[edge_idx].first;
    int v = edges[edge_idx].second;

    int target = a[u] + a[v];

    if (target > INF)
        return dp[edge_idx] = 1;

    if (tan[v].count(target))
    {
        int cached = tan[v][target];
        return dp[edge_idx] = (1 + cached) % MOD;
    }

    int cur = 0;
    auto &vec = adj[v];
    
    auto it = lower_bound(
        vec.begin(),
        vec.end(),
        make_pair(target, make_pair(-1, -1)),
        [](const auto &L, const auto &R)
        {
            return L.first < R.first;
        });

    while (it != vec.end() && it->first == target)
    {
        int next_edge = it->second.second;
        cur = (cur + dfs(next_edge, a, edges, adj, dp, tan)) % MOD;
        it++;
    }

    tan[v][target] = cur;

    return dp[edge_idx] = (1 + cur) % MOD;
}

void Solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<pair<int, int>> edges(m);
    vector<vector<pair<int, pair<int, int>>>> adj(n + 1);
    vector<int> dp(m, -1);
    vector<map<int, int>> tan(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        adj[u].push_back({a[v], {v, i}});
    }

    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end(),
             [](const auto &L, const auto &R)
             {
                 return L.first < R.first;
             });
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int t=dfs(i, a, edges, adj, dp, tan)%MOD;
        ans = (ans + t) % MOD;
    }

    cout << ans << "\n";
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