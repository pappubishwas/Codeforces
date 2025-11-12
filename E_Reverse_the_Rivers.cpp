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
    int n, m, x, k,q;
    cin >> n>>k>>q;
    vector<vector<int>> a(k,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>> a[j][i];
        }
    }
    for(int i=0;i<k;i++){
        for(int j=1;j<n;j++){
            a[i][j] |=a[i][j-1];
        }
    }
    while(q--){
        cin>>m;
        int l=0LL,r=n-1;
        while(m--){
            int re,c;
            char ch;
            cin>>re>>ch>>c;
            re--;
            if(ch=='>'){
                int t=upper_bound(a[re].begin(),a[re].end(),c)-a[re].begin();
                l=max(l,t);
            }else{
                int t=lower_bound(a[re].begin(),a[re].end(),c)-a[re].begin();
                r=min(r,t-1);
            }
        }
        if(l<=r){
            cout<<l+1<<endl;
        }else{
            cout<<-1<<endl;
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

    //cin >> t;

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