#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
int MOD=1e9+7;

void Solve() 
{
    int n;
    cin>>n;
    vector<int> ans(n+1,0);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        if(v==0 && u==0) continue;
        adj[i+1].push_back(v);
        adj[i+1].push_back(u);
    }
    vector<int> child(n+1,0);
    auto dfs=[&](auto&& self,int u,int p)->void{
        for(auto v:adj[u])
        {
            if(v==p) continue;
            self(self,v,u);
            child[u]+=child[v];
        }
        child[u]++;
    };
    auto dfs2=[&](auto&& self,int u,int p)->void{
        ans[u]=(2LL*(child[u]-1)+1+ans[p])%MOD;
        for(auto v:adj[u])
        {
            if(v==p) continue;
            self(self,v,u);
        }
    };
    dfs(dfs,1,0);
    dfs2(dfs2,1,0);
    //cout<<child[1]<<endl;
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}