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
void Solve()
{
    int n, x, r, d, m;
    cin>> n>>x;
    vector<int> pap(n),b(n),prefix(n+1),suffix(n+1);
    for(int i=0;i<n;i++){
        cin>>pap[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int total=INT_MIN;
    for(int i=n-1;i>=0;i--){
        suffix[i]=suffix[i+1]+pap[i];
        suffix[i]=max(pap[i],suffix[i]);
        total=max(total,suffix[i]);
    }
    if(x%2==0){
        cout<<total<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        prefix[i+1]=prefix[i]+pap[i];
        prefix[i+1]=max(prefix[i+1],pap[i]);
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,prefix[i]+pap[i]+suffix[i+1]+b[i]);
        ans=max(ans,prefix[i]+pap[i]+b[i]);
        ans=max(ans,pap[i]+suffix[i+1]+b[i]);
        ans=max(ans,pap[i]+b[i]);
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
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}