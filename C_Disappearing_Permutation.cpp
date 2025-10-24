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

int binaryLength(int n)
{
    return 64 - __builtin_clzll(n);
}

int dfs(int node,vector<vector<int>> &adj,vector<bool> &visited){
    if(visited[node]) return 0;
    visited[node]=true;
    int count=1;
    for(auto neigh:adj[node]){
        if(!visited[neigh]){
            count+=dfs(neigh,adj,visited);
        }
    }
    return count;
}

void Solve()
{
    int n, q, x, a, b;
    cin >> n;
    vector<int> pap(n);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n;i++){
        cin>>x;
        adj[x].push_back(i+1);
        adj[i+1].push_back(x);
    }
    for(int i=0;i<n;i++){
        cin>>pap[i];
    }
    vector<bool> visited(n+1,false);
    vector<int> ans(n+1,0);
    for(int i=0;i<n;i++){
        int temp=dfs(pap[i],adj,visited);
        ans[i+1]=ans[i]+temp;
    } 
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}