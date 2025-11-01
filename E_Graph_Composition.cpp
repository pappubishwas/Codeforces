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

class DSU{
    public:
    vector<int> rank;
    vector<int> parent;
    DSU(int n){
        rank.assign(n+1,0);
        parent.assign(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x]==x) return x;

        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px==py) return;

        if(rank[px]>rank[py]){
            parent[py]=px;
        }else if(rank[px]<rank[py]){
            parent[px]=py;
        }else{
            parent[px]=py;
            rank[py]++;
        }
    }
};


void solve()
{
    int n, m, k,m1,m2;
    cin >> n >>m1>>m2;
    vector<pair<int,int>> edges1,edges2,upedges1;
    DSU F(n),G(n);
    for(int i=0;i<m1;i++){
        int u,v;
        cin>>u>>v;
        edges1.push_back({u,v});
    }
    for(int i=0;i<m2;i++){
        int u,v;
        cin>>u>>v;
        G.Union(u,v);
        edges2.push_back({u,v});
    }
    int ans=0;

    for(int i=0;i<m1;i++){
        int u=edges1[i].first;
        int v=edges1[i].second;
        if(G.find(u)==G.find(v)){
            // upedges1.push_back(edges1[i]);
            F.Union(u,v);
        }else{
            ans++;
        }
    }
    for(int i=0;i<m2;i++){
        int u=edges2[i].first;
        int v=edges2[i].second;
        if(F.find(u)!=F.find(v)){
            // upedges1.push_back(edges1[i]);
            F.Union(u,v);
            ans++;
        }
    }
    cout<<ans<<endl;

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


