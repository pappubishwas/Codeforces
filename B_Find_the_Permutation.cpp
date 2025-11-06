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


void solve()
{
    int n, m, k;
    cin >> n;
    vector<vector<int>> adj(n+1);
    vector<int> indeg(n+1,0),ans;
    for(int i=1;i<=n;i++){
        string s;
        cin>> s;
        for(int j=i+1;j<=n;j++){
            if(s[j-1]=='1'){
                adj[i].push_back(j);
                indeg[j]++;
            }else{
                adj[j].push_back(i);
                indeg[i]++;
            }
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0) q.push(i);
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        ans.push_back(u);
        for(int v:adj[u]){
            indeg[v]--;
            if(indeg[v]==0) q.push(v);
        }
    }
    for(auto t:ans) cout<<t<<" ";
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
        solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}


