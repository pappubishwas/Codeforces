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
map<int,int>mp;
int solve(int n,int k){
    if(n<k) return INF;
    if(n==k) return 0;
    if(mp.find(n)!=mp.end()) return mp[n];
    int l=n/2LL;
    int r=(n+1)/2LL;
    int res=INF;
    if(l==r){
        res=solve(l,k);
    }else{
        res=min(res,solve(l,k));
        res=min(res,solve(r,k));
    }
    if(res==INF) return INF;
    return mp[n]=res+1;
}

struct DSU {
    vector<int> parent, rank;

    DSU(int n = 0) { init(n); }

    void init(int n) {
        parent.resize(n);
        rank.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    void Union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]){
            parent[x]=y;
            rank[y]+=rank[x];
        }else{
            parent[y]=x;
            rank[x]+=rank[y];
        }
    }

    int size(int v) {
        return rank[find(v)];
    }
};
void Solve()
{
    int n;
    cin >> n;
    vector<int> pap(n),ans(n+1,0);
    vector<bool> visited(n - 1, false);
    DSU ds(n - 1);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i) cin >> pap[i];
    for (int i = 0; i < n - 1; ++i) {
        int d = abs(pap[i] - pap[i + 1]);
        adj[d].push_back(i);
    }
    int total = 0;
    for (int k = n - 1; k >= 1; k--) {
        for (int i : adj[k]) {
            int a,b,cnt1,cnt2;
            if (i + 1 < n - 1 && visited[i + 1]) {
                 a = ds.find(i);
                 b = ds.find(i + 1);
                 cnt1=ds.size(a);
                 cnt2=ds.size(b);
                if (a != b) {
                    total -= (cnt1*(cnt1+1)/2LL);
                    total -= (cnt2*(cnt2+1)/2LL);
                    ds.Union(a, b);
                    a = ds.find(i);
                    cnt1=ds.size(a);
                    total += (cnt1*(cnt1+1)/2LL);
                }
            }
            if (i > 0 && visited[i - 1]) {
                 a = ds.find(i);
                 b = ds.find(i - 1);
                 cnt1=ds.size(a);
                 cnt2=ds.size(b);
                if (a != b) {
                    total -= (cnt1*(cnt1+1)/2LL);
                    total -= (cnt2*(cnt2+1)/2LL);
                    ds.Union(a, b);
                     a = ds.find(i);
                    cnt1=ds.size(a);
                    total += (cnt1*(cnt1+1)/2LL);
                }
            }
            visited[i] = true;
            total++;
        }
        ans[k] = total;
    }
    for (int k = 1; k < n; ++k) {
        cout << ans[k] << " ";
    }
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