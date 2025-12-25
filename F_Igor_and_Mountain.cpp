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
const int mod = 998244353;
const int MOD = 1e9 + 7;
int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }
int fact[200001];
int powerl(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int inMod(int a)
{
    return powerl(a, mod - 2);
}
void Solve()
{
    int n,m,d;
    cin >> n>>m>>d;
    vector<string> g(n);
    for(int i=0;i<n;i++){
        cin>>g[i];
    }
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(2,0))),pre(n,vector<vector<int>>(m+1,vector<int>(2,0)));
    
    for(int j=0;j<m;j++){
        if(g[n-1][j]=='X') dp[n-1][j][0]=1;
    }
    for(int i=0;i<m;i++){
        pre[n-1][i+1][0]=(pre[n-1][i][0]+dp[n-1][i][0]+mod)%mod;
    }
    
    int sq=sqrtl(d*d-1);
    for(int j=0;j<m;j++){
        if(g[n-1][j]=='#') continue;
        int low=max(0LL,j-d),high=min(m-1LL,j+d);
        dp[n-1][j][1]=(pre[n-1][high+1][0]-pre[n-1][low][0]-dp[n-1][j][0]+mod)%mod;
    }
    for(int j=0;j<m;j++){
        pre[n-1][j+1][1]=(pre[n-1][j][1]+dp[n-1][j][1]+mod)%mod;
    }

    for(int i=n-2;i>=0;i--){
        for(int j=0;j<m;j++){
            if(g[i][j]=='#') continue;
            int low=max(0LL,j-sq),high=min(m-1LL,j+sq);
            dp[i][j][0]=(pre[i+1][high+1][1]-pre[i+1][low][1]+mod)%mod;
            dp[i][j][0]=(dp[i][j][0]+(pre[i+1][high+1][0]-pre[i+1][low][0])+mod)%mod;
        }
        for(int j=0;j<m;j++){
            pre[i][j+1][0]=(pre[i][j][0]+dp[i][j][0]+mod)%mod;
        }
        for(int j=0;j<m;j++){
            if(g[i][j]=='#') continue;
            int low=max(0LL,j-d),high=min(m-1LL,j+d);
            dp[i][j][1]=(pre[i][high+1][0]-pre[i][low][0]-dp[i][j][0]+mod)%mod;
        }
        for(int j=0;j<m;j++){
            pre[i][j+1][1]=(pre[i][j][1]+dp[i][j][1]+mod)%mod;
        }
    }
    cout<<((pre[0][m][0]+pre[0][m][1])%mod)<<endl;
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