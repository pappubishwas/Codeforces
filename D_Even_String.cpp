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

int mod=998244353;
static const int N = 1000000;   
int fac[N + 1], infact[N + 1];

int powEx(int b,int e){
    int res=1;
    while(e>0){
        if(e&1){
            res=(res*b)%mod;
        }
        b=(b*b)%mod;
        e/=2;
    }
    return res;
}

void preCompute(){
    fac[0]=1;
    infact[0]=1;
    for(int i=1;i<=N;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
    infact[N]=powEx(fac[N],mod-2);
    for(int i=N-1;i>0;i--){
        infact[i] = (infact[i+1] * (i+1)) % mod;
    }
}

void Solve()
{
    int n, k,x,m;
    vector<int> c(27);
    for(int i=1;i<27;i++) cin>> c[i];
    n=accumulate(c.begin(),c.end(),0LL);
    vector<vector<int>> dp(27,vector<int>(n,0));
    dp[0][0]=1;
    for(int i=1;i<27;i++){
        for(int j=0;j<=n/2;j++){
            dp[i][j]=dp[i-1][j];
            if(c[i]>0 && j-c[i]>=0){
                dp[i][j]=(dp[i][j]+dp[i-1][j-c[i]])%mod;
            }
        }
    }
    int ans=(dp[26][n/2]*fac[n/2]%mod*fac[(n+1)/2])%mod;
    for(int i=1;i<27;i++){
        ans=(ans*infact[c[i]])%mod;
    }
    cout<<ans<<endl;
}

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    preCompute();
    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    return 0;
}