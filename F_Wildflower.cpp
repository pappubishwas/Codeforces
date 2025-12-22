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
//const int mod = 998244353;
const int mod = 1e9 + 7;
int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }

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
int dfs1(int node, int p,vector<vector<int>>& adj){
    int res=1;
    for(int v:adj[node])
            if(v!=p) res+=dfs1(v,node,adj);
    return res;        
}
int dfs(int node,int p,vector<vector<int>>& adj){
    if(adj[node].size()==3 || (node==1 && adj[node].size()==2)){
        vector<int> t;
        for(int v:adj[node])
            if(v!=p) t.push_back(dfs1(v,node,adj));
        
        int diff=abs(t[0]-t[1]);
        int res=powerl(2,diff)%mod;
        res=(res+powerl(2,max(0LL,diff-1)))%mod; 
        return (2LL*res)%mod;
    }else{
        int res=2;
        for(int v:adj[node])
            if(v!=p) res =res*dfs(v,node,adj)%mod;
        return res;    
    }
}
void Solve()
{
    int n, k, q;
    cin >> n;
    vector<int> indeg(n+1);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>> u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        indeg[u]++;
        indeg[v]++;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(i!=1 && indeg[i]==1) cnt++;
    }
    if(cnt>2){
        cout<<0<<endl;
        return;
    }
    int ans=dfs(1,0,adj)%mod;
    cout<<ans<<endl;
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