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
    int n;
    vector<int> p,rank;
    DSU(int sz){
        p.assign(sz,0);
        rank.assign(sz,0);
        for(int i=0;i<sz;i++) p[i]=i;
    }
    int find(int x){
        if(p[x]==x) return x;
        return p[x]=find(p[x]);
    }
    void Unite(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px==py) return;
        if(rank[px]<rank[py]){
            p[px]=py;
        }else if(rank[px]>rank[py]){
            p[py]=px;
        }else{
            p[py]=px;
            rank[px]++;
        }
    }
};
void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    int gd=__gcd(a,b);
    vector<int> pap(n);
    for(int i=0;i<n;i++){
        cin>>pap[i];
        pap[i]%=gd;
    }
    sort(pap.begin(),pap.end());
    int ans=pap[n-1]-pap[0];
    for(int i=1;i<n;i++){
        ans=min(ans,pap[i-1]+gd-pap[i]);
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