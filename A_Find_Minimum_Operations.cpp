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


void Solve() 
{
    int n, m;
    cin >> n >> m;
    if(m==1 || m>n) cout<<n<<endl;
    else{
        int ans=0;
        while(n>0){
            int curr=1;
            while(curr*m<=n){
                curr*=m;
            }
            n-=curr;
            ans++;
            if(m>n){
                ans+=n;
                break;
            }
        }
        cout<<ans<<endl;
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