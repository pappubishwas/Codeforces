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
    int n, m, v, k;
    cin >> n >> m >> k;
    vector<int> distance(k + 1), type(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> type[i];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    distance[type[1]] = 0;
    vector<bool> visited(n + 1, false);
    visited[1] = true;
    int level = 1;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
            {
                if (!visited[v])
                {
                    distance[type[v]] = max(distance[type[v]], level);
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        level++;
    }
    for (int i = 1; i <= k; i++)
    {
        cout << distance[i] << " ";
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

    // cin >> t;

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