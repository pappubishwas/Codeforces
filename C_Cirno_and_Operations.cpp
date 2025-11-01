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
    int n, m, k;
    cin >> n;
    vector<int> pap(n);
    for(int i=0;i<n;i++) cin>>pap[i];
    int ans=(accumulate(pap.begin(),pap.end(),0LL));
    while (n>1)
    {
        vector<int> v;
        for(int i=0;i<n-1;i++){
            v.push_back(pap[i+1]-pap[i]);
        }
        ans=max(ans,abs(accumulate(begin(v),end(v),0LL)));
        for(int i=0;i<n-1;i++){
            pap[i]=v[i];
        }
        n--;
    }
    cout<<max(ans,pap[0])<<endl;
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


