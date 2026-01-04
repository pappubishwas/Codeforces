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
vector<vector<int>> dp;
int dfs(int idx,int carry,int n,string& s1,string& s2){
    if(idx>=n){
        return 0;
    }
    if(dp[idx][carry]!=-1) return dp[idx][carry];
    int newCarry=(carry+(s1[idx]-'0'))%2;
    int par=s2[idx]-'0';
    int res=INF;
    if(par==newCarry){
        res=dfs(idx+1,newCarry,n,s1,s2);
    }else{
        res=1+dfs(idx+1,0,n,s1,s2);
        res=min(res,1+dfs(idx+1,1,n,s1,s2));
    }
    return dp[idx][carry]=res;
}
void Solve()
{
    string t1,t2;
    cin>>t1>>t2;
    int n=t1.size();
    dp.assign(n+1,vector<int>(2,-1));
    cout<<dfs(0,0,n,t1,t2)<<endl;
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