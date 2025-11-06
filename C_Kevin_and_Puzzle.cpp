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

int solve(int i,int n,vector<int>& pap,vector<int>& dp){
    if(i==0) return pap[1]==0;
    if(i==1){
        int res=0;
        if(pap[i]==0 && (n==1 || pap[i+1]==0)) res++;
        if(n==1 || pap[i+1]==1) res++;
        return res;
    }
    if(dp[i]!=-1) return dp[i];
    dp[i]=0;
    if(pap[i]<i && (i==n || pap[i]==pap[i+1])) // current is honest, previous one was definetly honest otherwise i won't call next one, only i call next one when current one is honest;
    {
        dp[i]+=solve(i-1,n,pap,dp); // if current one is honest then next one could be honest or liar 
    }
    if(i==n || (pap[i-1]+1==pap[i+1])) // if current one is liar then definetly left and right both are honest if they are honest and in between them thier is one liar then, left and right different will be 1
    {
        dp[i]+=solve(i-2,n,pap,dp); // if current one is liar then previous one is definetly honest , then need to call previous one 
    }
    dp[i]%=mod;
    return dp[i];
}


void solve()
{
    int n, m, k;
    cin >> n;
    vector<int> pap(n+1),dp(n+1,-1);
    for(int i=1;i<=n;i++) cin>>pap[i];
    cout<<solve(n,n,pap,dp)<<endl;   
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


