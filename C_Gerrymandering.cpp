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
    cin>>n;
    vector<string> g(2);
    cin>>g[0]>>g[1];
    map<pair<int,int>,int> dp;
    auto check=[&](pair<int,int>a,pair<int,int>b,pair<int,int>c)->int{
        return ((g[a.first][a.second]=='A')+(g[b.first][b.second]=='A') + (g[c.first][c.second]=='A')>=2);
    };

    function<int(int,int)> fun=[&](int i,int j) -> int{
        if(i==n && j==n) return 0;
        if(dp.count({i,j})) return dp[{i,j}];

        int op1=(max(i+2,j+2) < n ? check({0,i},{0,i+1},{0,i+2})+check({1,j},{1,j+1},{1,j+2})+fun(i+3,j+3) : 0);
        int op2= ((i==j || i+1==j) ? check({0,i},{0,i+1},{1,j})+fun(i+2,j+1) : 0);
        int op3= ((i==j || i==j+1) ? check({0,i},{1,j+1},{1,j})+fun(i+1,j+2) : 0);
        return dp[{i,j}]=max({op1,op2,op3});
    };
    cout<<fun(0,0)<<endl;
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