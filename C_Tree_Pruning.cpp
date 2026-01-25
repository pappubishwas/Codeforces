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
const int MOD = 1e9 + 7;
int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }
int powerl(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
int inMod(int a)
{
    return powerl(a, MOD - 2);
}
class DSU
{
private:
    int n;
    vector<int> parent, rank;

public:
    DSU(int sz)
    {
        this->n = sz;
        parent.assign(n + 1, 0);
        rank.assign(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
        // for(int i=0;i<=n;i++) parent[i]=i;
    }
    int find(int x)
    {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return;
        if (rank[px] < rank[py])
        {
            parent[px] = py;
        }
        else if (rank[px] > rank[py])
        {
            parent[py] = px;
        }
        else
        {
            parent[px] = py;
            rank[py]++;
        }
    }
};

int dfs(int u, int p, vector<set<int>> &adj)
{
    if (adj[u].size() > 2 || u==1)
    {
        adj[u].erase(p);
        return 0;
    }
    int res=1;
    for (auto& v : adj[u])
    {
        if (p != v)
        {
            res+=dfs(v,u,adj);
        }
    }
    return res;
}

void Solve()
{
    int n, m;
    cin >> n;
    vector<set<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    int upCount = 0, upRemove = 0, ans = n - 1;
    queue<int> q;
    q.push(1);
    vector<bool> visited(n + 1);
    visited[1] = true;
    while (!q.empty())
    {
        vector<int> leaf;
        int sz = q.size();
        upCount += sz;
        while (sz--)
        {
            int u = q.front();
            bool isLeaf = true;
            q.pop();
            for (auto& v : adj[u])
            {
                if (!visited[v])
                {
                    isLeaf = false;
                    visited[v] = true;
                    q.push(v);
                }
            }
            if (isLeaf)
            {
                leaf.push_back(u);
            }
        }
        ans = min(ans, n - upCount + upRemove);
        for (int &l : leaf)
        {
            upRemove += dfs(l, l, adj);
        }
    }
    cout << ans << endl;
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