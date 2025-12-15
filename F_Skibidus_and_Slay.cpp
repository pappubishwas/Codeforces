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

// void dfs(int p,int c,string& s,vector<int>& a,vector<vector<int>>& adj,map<int,map<int,int>>& val){
//     int parantVal=a[p];
//     int childVal=a[c];
//     if(s[parantVal]=='0' && parantVal==childVal){
//         s[parantVal]='1';
//     }else{
//         auto& st=val[c];
//         if(st[parantVal]>1){
//             s[parantVal]='1';
//         }
//         if(st[childVal]>0){
//             s[childVal]='1';
//         }
//         for(auto& t:st){
//             if(t.second>1){
//                 s[t.first]='1';
//             }
//         }
//     }
//     for(int ch:adj[c]){
//         if(p!=ch){
//             dfs(c,ch,s,a,adj,val);
//         }
//     }
// }
// void Solve()
// {
//     int n, x, y, l, k, r, p;
//     cin>>n;
//     vector<int> vval(n+1);
//     for(int i=1;i<=n;i++){
//         cin>>vval[i];
//     }
//     vector<vector<int>> adj(n+1);
//     map<int,map<int,int>> mp;
//     for(int i=0;i<n-1;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//         mp[u][vval[v]]++;
//         mp[v][vval[u]]++;
//     }
//     string s=string(n+1,'0');
//     dfs(0,1,s,vval,adj,mp);
//     cout<<s.substr(1,n)<<endl;
// }


void Solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    string ans(n, '0');



    for (int u = 1; u <= n; ++u) {
        set<int> nbr;
        for (int v : adj[u]) { 
            if (a[u] == a[v]) { // if nbr has same value then it's simple path
                ans[a[u] - 1] = '1';
            }
            if(nbr.count(a[v])) ans[a[v]-1]='1';
            nbr.insert(a[v]); // store the nbr value
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