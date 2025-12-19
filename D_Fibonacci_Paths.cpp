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

void Solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<map<int,int>> dp(n+1);
    vector<array<int,3>> ed;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        ed.push_back({a[u]+a[v],u,v});
        dp[v][a[u]+a[v]]+=1;  //count of ending at v with sum of two consecutive node a[u]+a[v]
    }

    sort(ed.begin(),ed.end()); // those pair value are low they have possiblity to create fibo sequence with creater value 

    for(auto [w,u,v]:ed){
        // u->v
        if(dp[u].find(a[v])!=dp[u].end()){ // for node v if want to create sequence with u those are ending at node u with sum a[v] those will create the simple path
            dp[v][a[u]+a[v]]+=dp[u][a[v]];
            dp[v][a[u]+a[v]]%=MOD;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(auto [x,y]:dp[i]){
            ans=(ans+y)%MOD;
        }
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