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
class DSU{
    private:
        int n;
        vector<int> parent,rank;
        public:
        DSU(int sz){
            this->n=sz;
            parent.assign(n+1,0);
            rank.assign(n+1,0);
            iota(parent.begin(),parent.end(),0);
            //for(int i=0;i<=n;i++) parent[i]=i;
        }
        int find(int x){
            if(parent[x]==x) return x;

            return parent[x]=find(parent[x]);
        }
        void Union(int x,int y){
            int px=find(x);
            int py=find(y);
            if(px==py) return;
            if(rank[px]<rank[py]){
                parent[px]=py;
            }else if(rank[px]>rank[py]){
                parent[py]=px;
            }else{
                parent[px]=py;
                rank[py]++;
            }
        }
};
// void Solve()
// {
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>> kd(n+1,vector<int>(11,-1));
//     DSU dsu(n);
//     while(m--){
//         int a,d,k;
//         cin>>a>>d>>k;
//         if(d==0) continue;
//         int s=0;
//         while(s<k){
//             int cp=a+s*d;
//             if(kd[cp][d]!=-1){
//                 int ml=k-s;
//                 //cout<<ml<<endl;
//                 if(ml<=kd[cp][d]){
//                     break;
//                 }else{
//                     s+=kd[cp][d];
//                     kd[cp][d]=ml;
//                 }
//             }else{
//                 kd[cp][d]=k-s;
//                 dsu.Union(cp,cp+d);
//                 s++;
//             }
//         }
//     }
//     set<int> st;
//     for(int i=1;i<=n;i++){
//         int p=dsu.find(i);
//         st.insert(p);
//     }
//     cout<<st.size()<<endl;
// }

void Solve() 
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> dp(n + 1, vector<int>(11, -INF));
    for (int i = 1; i <= m; i++){
        int a, d, k; cin >> a >> d >> k;
        dp[a][d] = max(dp[a][d], k);
    }
    
    DSU uf(n);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 10; j++){
            if (dp[i][j] >= 1){
                int nx = i + j;
                uf.Union(nx, i);
                dp[nx][j] = max(dp[nx][j], dp[i][j] - 1);
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += uf.find(i) == i;
    
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