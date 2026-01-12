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
vector<set<int>> adj;
vector<vector<int>> ans;
set<int> st;
vector<bool> visited;
void dfs(int u,int p){
    visited[u]=true;
    vector<int> child;
    for(int v:adj[u]){
        if(v!=p) child.push_back(v);
    }
    while(child.size()>=2){
        int a=child.back();
        child.pop_back();
        int b=child.back();
        child.pop_back();
        adj[u].erase(b);
        adj[u].erase(a);
        adj[a].erase(u);
        adj[b].erase(u);
        if(adj[a].find(b)==adj[a].end()){
            adj[a].insert(b);
            adj[b].insert(a);
        }else{
            adj[a].erase(b);
            adj[b].erase(a);
        }
        ans.push_back({u,a,b});
    }
    if(child.size()){
        dfs(child[0],u);
    }else{
        st.insert(u);
    }
}
void Solve()
{
    int n,m;
    cin>>n>>m;
    adj.clear();
    st.clear();
    visited.clear();
    ans.clear();
    visited.assign(n+1,false);
    adj.assign(n+1,set<int>());
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    if(m==0){
        cout<<0<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i,-1);
        }
    }
    int a=-1;
    for(int c:st){
        if(adj[c].size()){
            a=c;
            st.erase(c);
            break;
        }
    }
    if(a!=-1){
        int b=*adj[a].begin();
        for(int c:st){
            ans.push_back({a,b,c});
            b=c;
        }
    }
    cout<<ans.size()<<endl;
    for(auto c:ans){
        cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<endl;
    }
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