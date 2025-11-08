// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace std;
// using namespace __gnu_pbds;
// #define int long long
// #define INF (int)1e18
// mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
// template <class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }

// int binaryLength(int n)
// {
//     return 64 - __builtin_clzll(n);
// }
// int mod = 998244353;

// vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};

// int dp[1001][1001];

// int ans(int i,int j,string& a,string& b,string& c){
//     if(i+j>=c.size()) return 0;
//     //if(i>=a.size() || j>=b.size()) return 0;

//     if(dp[i][j]!=-1) return dp[i][j];
//     int op=LLONG_MAX;
//     if(i<a.size() && c[i+j]==a[i]){
//         op=ans(i+1,j,a,b,c);
//         if(j<b.size() && c[i+j]==b[j]){
//             op=min(op,ans(i,j+1,a,b,c));
//         }else if(j<b.size()){
//             op=min(op,1+ans(i,j+1,a,b,c));
//         }
//     }else if(j<b.size() && c[i+j]==b[j]){
//         op=ans(i,j+1,a,b,c);
//         if(i<a.size() && c[i+j]==a[i]){
//             op=min(op,ans(i+1,j,a,b,c));
//         }else if(i<a.size()){
//             op=min(op,1+ans(i+1,j,a,b,c));
//         }
//     }else{
//         int takea=LLONG_MAX;
//         if(i<a.size())
//             takea=1+ans(i+1,j,a,b,c);
//         int takeb=LLONG_MAX;
//         if(j<b.size())
//             takeb=1+ans(i,j+1,a,b,c);
//         op=min(takea,takeb);
//     }
//     return dp[i][j]=op;
// }

// void solve()
// {
//     int n,k;
//     string a,b,c;
//     cin>>a>>b>>c;
//     n=a.size();
//     int m=b.size();
//     cout<<ans(0,0,a,b,c)<<endl;
// }

// int32_t main()
// {
//     auto begin = chrono::high_resolution_clock::now();
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int t = 1;
//     // freopen("in",  "r", stdin);
//     // freopen("out", "w", stdout);

//     cin >> t;
//     for (int i = 1; i <= t; i++)
//     {
//         // cout << "Case #" << i << ": ";
//         memset(dp,-1,sizeof(dp));
//         solve();
//     }

//     auto end = chrono::high_resolution_clock::now();
//     auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
//     // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int> > dp;

// int helper(int i, int j, string &a, string &b, string &c)
// {
//     if (i == a.size() && j == b.size())
//         return 0;
//     if (dp[i][j] != -1)
//         return dp[i][j];

//     int pos = i + j;
//     int res = 1e9;

//     if (i < a.size())
//     {
//         int cost = helper(i + 1, j, a, b, c) + (a[i] != c[pos]);
//         res = min(res, cost);
//     }
//     if (j < b.size())
//     {
//         int cost = helper(i, j + 1, a, b, c) + (b[j] != c[pos]);
//         res = min(res, cost);
//     }

//     return dp[i][j] = res;
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         string a, b, c;
//         cin >> a >> b >> c;
//         int n = a.size();
//         int m = b.size();
//         dp.assign(n + 1, vector<int>(m + 1, -1));
//         cout << helper(0, 0, a, b, c) << endl;
//     }
//     return 0;
// }

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
    int n, k;
    string a, b, c;
    cin >> a >> b >> c;
    n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i)
            {
                int val = a[i - 1] != c[i + j - 1]; // if i-1 th char of a is not equal then we need one operations
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + val);
            }
            if (j)
            {
                int val = b[j - 1] != c[i + j - 1]; // if j-1 th char of b is not equal then we need one more operations of prev state
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + val);
            }
        }
    }
    cout << dp[n][m] << endl;
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