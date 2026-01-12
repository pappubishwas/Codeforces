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
    int n;
    cin >>n;
    vector<int> pap(n);
    for(int i=0;i<n;i++) cin>>pap[i];
    int x=0;
    vector<int> dp(n+1),premx(n+1);
    for(int i=0;i<n;i++){
        if(pap[i]>x){
            x++;
        }else if(pap[i]<x) x--;
        premx[i+1]=max(premx[i],x); // interval l<=(r=i)
    }
    dp[0]=0; // till index i maximum val of x where interval is 1<=l<=r<=(i-1)
    for(int i=1;i<n;i++){
        int y=dp[i-1]; // interval l to r is in between  1 to i-1
        if(y>pap[i]) y--;
        else if(y<pap[i]) y++;
        dp[i]=max(y,premx[i]); // if premx[i] is max means i-1
    }
    cout<<dp[n-1]<<endl;
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