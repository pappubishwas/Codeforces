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
const int mod = 998244353;
const int MOD = 1e9 + 7;
int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }
int fact[200001];
int powerl(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int inMod(int a)
{
    return powerl(a, mod - 2);
}
void Solve()
{
    int n, m, k;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1), indeg2(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); 
        adj[v].push_back(u);
        indeg[u]++;
        indeg[v]++;
    }
    if (m != n - 1) // it should be connected tree
    {
        cout << 0 << endl;
        return;
    }
    int cnt = 0; // count how many node are not leaf node
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 1) // leaft node
            continue;
        cnt++;
        for (int v : adj[i]) 
            if (indeg[v] != 1) // if not leaf node then increase the count of no leaf node connected the curr node i
                indeg2[i]++;
    }
    for (int i = 1; i <= n; i++)
        if (indeg2[i] > 2) // if any no leaf node has indegree more than 2 then not possible
        {
            cout << 0 << endl;
            return;
        }
    int ans = 0;
    if (cnt >= 2) // if no leaf node are more than 1 then we can arrange on 4 ways
        ans = 4;
    else // otherwise 2 ways
        ans = 2;
    
    for(int i=1;i<=n;i++){ 
        int leaf=0;
        for(int v:adj[i]){ // count the the leaf node of current node
            if(indeg[v]==1) leaf++;
        }
        ans=(ans*fact[leaf])%MOD; // those leaf node can be arrange within them on leaf! ways
    }
    cout<<ans<<endl;
}

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    fact[0] = 1;
    for (int i = 1; i <= 200000; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    return 0;
}