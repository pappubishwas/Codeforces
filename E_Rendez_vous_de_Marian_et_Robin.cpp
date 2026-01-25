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
void dij(int s, vector<vector<pair<int,int>>>& adj,
         vector<vector<int>>& cost, set<int>& horse)
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    int h = horse.count(s) ? 1 : 0;
    pq.push({0, s, h});
    cost[s][h] = 0;

    while(!pq.empty()){
        auto curr = pq.top(); pq.pop();

        int w = curr[0];
        int u = curr[1];
        int hasHorse = curr[2];

        if(w > cost[u][hasHorse]) continue; 

        for(auto &it : adj[u]){
            int v = it.first;
            int wt = it.second;

            if(hasHorse) wt /= 2;

            int nh = hasHorse;
            if(!hasHorse && horse.count(v)) nh = 1;

            if(w + wt < cost[v][nh]){
                cost[v][nh] = w + wt;
                pq.push({w + wt, v, nh});
            }
        }
    }
}


void Solve()
{
    int n,m,h;
    cin>>n>>m>>h;
    set<int> horse;
    for(int i=0;i<h;i++){
        int hr;
        cin>>hr;
        horse.insert(hr);
    }
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<vector<int>> cost1(n+1,vector<int>(2,INF)),costn(n+1,vector<int>(2,INF));
    dij(1,adj,cost1,horse);
    dij(n,adj,costn,horse);
    int ans=INF;
    for(int i = 1; i <= n; i++){
    int best1 = min(cost1[i][0], cost1[i][1]);
    int bestn = min(costn[i][0], costn[i][1]);
    ans = min(ans, max(best1, bestn));
    }
    if(ans==INF) ans=-1;
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