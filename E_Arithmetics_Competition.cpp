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
void solve() {
    int n,m,q;
    cin>> n>>m>>q;
    vector<int> pa(n+1),pb(m+1),pab(n+m+1),a(n+1),b(m+1),ab(n+m+1);
    for(int i=1;i<=n;i++) cin>> a[i];
    for(int i=1;i<=m;i++) cin>> b[i];
    sort(a.begin()+1,a.end(),greater<int>());
    sort(b.begin()+1,b.end(),greater<int>());
    for(int i=1;i<=n+m;i++){
        if(i<=n) ab[i]=a[i];
        else ab[i]=b[i-n];
    }
    sort(ab.begin()+1,ab.end(),greater<int>());
    for(int i=1;i<=n;i++){
        pa[i]=pa[i-1]+a[i];
    }
    for(int i=1;i<=m;i++){
        pb[i]=pb[i-1]+b[i];
    }
    for(int i=1;i<=n+m;i++){
        pab[i]=pab[i-1]+ab[i];
    }

    while(q--){
        int x,y,z;
        cin>> x>>y>>z;
        if(x==0){ // take all from b
            cout<<pb[z]<<endl;
            continue;
        }
        if(y==0){ // take all from a
            cout<<pa[z]<<endl;
            continue;
        }

        if(x<z && a[x]>b[z-x]){ // if taking x from a and z-x from b is better
            cout<<pa[x]+pb[z-x]<<endl;
        }else if(y<z && b[y]>a[z-y]){ // if taking y from b and z-y from a is better
            cout<<pb[y]+pa[z-y]<<endl;
        }else{
            cout<<pab[z]<<endl; // take best z from both
        }
    }
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