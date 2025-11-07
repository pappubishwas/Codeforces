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
    int n, kmax;
    cin >> n ;
    vector<int> pap(n+1);
    vector<pair<int,int>> ans,res;
    for(int i=1;i<=n;i++){
        cin>>pap[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j++){
            if(pap[j]<pap[j+1]){
                ans.push_back({pap[j],pap[j+1]});
                swap(pap[j],pap[j+1]);
            }
        }
    }

    reverse(ans.begin(),ans.end());
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            res.push_back({i,j});
        }
    }
    for(auto [x,y]:ans) res.push_back({x,y});

    cout<<res.size()<<endl;
    for(auto [x,y]:res) cout<<x<<" "<<y<<endl;
}

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    // cin >> t;
    // for (int i = 1; i <= t; i++)
    // {
        // cout << "Case #" << i << ": ";
        solve();
    // }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
