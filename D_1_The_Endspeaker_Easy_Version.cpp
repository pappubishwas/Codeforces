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

void Solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> pap(n),tan(m+1),pref(n+1),dp(n+1,1e9);
    for(int i=0;i<n;i++){
        cin>>pap[i];
        pref[i+1]=pref[i]+pap[i];
    }
    for(int i=1;i<=m;i++) cin>>tan[i];
    dp[0]=0;
    for(int k=1;k<=m;k++){ // for every value k check each index in a 
        int val=tan[k];
        for(int i=0;i<n;i++){ 
            int need=val+pref[i];
            int idx=upper_bound(pref.begin(),pref.end(),need)-pref.begin()-1; // pref start with zero
            if(i==idx) continue;
            dp[idx]=min(dp[idx],dp[i]+m-k); // current index i to idx will cover by kth value of b,
        }
    }
    if(dp[n]>=1e9) dp[n]=-1;
    cout<<dp[n]<<endl;
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