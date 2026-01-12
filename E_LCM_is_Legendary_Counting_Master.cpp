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
const int MOD = 998244353;
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
vector<vector<int>> divisor(3001);
void precompute(){
    divisor[1].push_back(1);
    for(int i=2;i<=3000;i++){
        for(int j=1;j<=i;j++){
            if(i%j==0){
                divisor[i].push_back(j);
            }
        }
    }
}

void Solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> pap(n);
    for(int i=0;i<n;i++){
        cin>>pap[i];
    }
    if(pap[0]>1){
        cout<<0<<endl;
        return;
    }
    vector<vector<int>> dp(n,vector<int>(m+1,0));
    dp[0][1]=1;
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            for(int d:divisor[j]){
                if(d+j<=m && (pap[i]==0 || (j+d)==pap[i])){
                    dp[i][j+d]=(dp[i][j+d]+ dp[i-1][j])%MOD;
                }
            }
        }
    }
    int ans=0;
    if(pap[n-1]!=0){
        cout<<dp[n-1][pap[n-1]]<<endl;
        return;
    }
    for(int i=1;i<=m;i++){
        ans=(ans+dp[n-1][i])%MOD;
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
    precompute();
    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    return 0;
}