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

int binaryLength(int n)
{
    return 64 - __builtin_clzll(n);
}

void Solve()
{
    int n, q, x, a, b;
    cin >> n;
    vector<int> pap(n);
    vector<pair<int,int>> res;
    bool need = false;
    for (int i = 0; i < n; i++)
    {
        cin >> pap[i];
    }
    for(int i=3;i<=n;i++){
        if(pap[i-1]==0) need=true;
    }
    if(need){
        res.push_back({3,n});
        n=3;
    }
    need=false;
    for(int i=1;i<=2;i++){
        if(pap[i-1]==0){
            need=true;
        }
    }
    if(need){
        res.push_back({1,2});
        n-=1;
    }
    res.push_back({1,n});
    cout<<res.size()<<endl;
    for(auto p:res){
        cout<<p.first<<" "<<p.second<<endl;
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
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}