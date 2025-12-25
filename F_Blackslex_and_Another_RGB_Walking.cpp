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
    string op;
    cin>> op;
    if(op=="first"){
        int t;
        cin>>t;
        while(t--){
            int n,m;
            cin>>n>>m;
            vector<vector<int>> adj(n+1);
            for(int i=0;i<m;i++){
                int u,v;
                cin>>u>>v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            queue<int> q;
            q.push(1);
            vector<int> dist(n+1,-1);
            dist[1]=0;
            while(!q.empty()){
                int v=q.front();
                q.pop();
                for(auto nb:adj[v]){
                    if(dist[nb]==-1){
                        dist[nb]=dist[v]+1;
                        q.push(nb);
                    }
                }
            }
            string ans="";
            string color="rgb";
            for(int i=1;i<=n;i++){
                ans+=color[dist[i]%3];
            }
            cout<<ans<<endl;
        }
    }else{
         int t;
        cin>>t;
        while(t--){
            int q;
            cin>>q;
            while (q--)
            {
                int n;
                cin>> n;
                string s;
                cin>> s;
                int r=0,g=0,b=0;
                for(int i=0;i<n;i++){
                    if(s[i]=='r') r=1;
                    else if(s[i]=='g') g=1;
                    else b=1;
                }
                char target=' ';
                if(r & g) target='g';
                else if(g & b) target='b';
                else if(b&r) target='r';
                else if(r) target='r';
                else if(g) target='g';
                else target='b';
                for(int i=0;i<n;i++){
                    if(target==s[i]){
                        cout<<i+1<<endl;
                        break;
                    }
                }
            }
            
        }
    }
}
int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    //cin >> t;

    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    return 0;
}