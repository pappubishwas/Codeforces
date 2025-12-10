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

// this failed, because i missed the point, it will move forward to the pi vertex
// bool dfs(deque<int>& q,set<int>& st, int p,int end,vector<vector<int>>& adj,vector<bool>& visited){
//     visited[p]=true;
//     q.push_back(p);
//     st.erase(p);
//     if(p==end) return true;
//     bool res=false;
//     for(int child:adj[p]){
//         if(!visited[child])
//         res |= dfs(q,st,child,end,adj,visited);
//     }
//     if(!res) {
//         st.insert(q.back());
//         q.pop_back();
//     }
//     return res;
// }

// void Solve()
// {
//     int n,s,e;
//     cin>>n>>s>>e;
//     vector<vector<int>> adj(n+1);
//     deque<int> q;
//     set<int> st;
//     for(int i=0;i<n-1;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//         st.insert(i+1);
//     }
//     st.insert(n);
//     vector<bool> visited(n+1,false);
//     dfs(q,st,s,e,adj,visited);
//     int cnt=st.size();
//     for(auto& node:st){
//         q.push_back(node);
//     }
//     if(cnt&1){
//         q.push_back(q.front());
//         q.pop_front();
//     }
//     for(auto x:q){
//         cout<<x<<" ";
//     }
//     cout<<endl;
// }

void inorder(int p,vector<vector<int>>& adj,vector<bool>& visited){
    visited[p]=true;
    for(int& v:adj[p]){
        if(!visited[v]) inorder(v,adj,visited);
    }
    cout<<p<<" ";
}

void Solve()
{
    int n, s, e;
    cin >> n >> s >> e;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n+1);
    inorder(e,adj,visited);
    cout<<endl;
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