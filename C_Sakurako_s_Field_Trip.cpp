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

bool find(vector<int>& a,int l,int r,int n){
    int curr=0,after=0;

    if(l-1>=0 && a[l-1]==a[l]) curr++;
    if(l+1<n && a[l+1]==a[l]) curr++;
    if(r-1>=0 && a[r-1]==a[r]) curr++;
    if(r+1<n && a[r+1]==a[r]) curr++;
    swap(a[l],a[r]);
    if(l-1>=0 && a[l-1]==a[l]) after++;
    if(l+1<n && a[l+1]==a[l]) after++;
    if(r-1>=0 && a[r-1]==a[r]) after++;
    if(r+1<n && a[r+1]==a[r]) after++;
    swap(a[l],a[r]);
    return after<curr;
}

// void solve()
// {
//     int n, m, x, k, q;
//     cin >> n;
//     vector<int> a(n);
//     for (auto &t : a)
//         cin >> t;
//     for(int i=1;i<=n/2;i++){
//         // bool ch=find(a,i,n-i-1,n);
//         // if(ch) swap(a[i],a[n-i-1]);

//         if(a[i]==a[i-1] || a[n-i-1]==a[n-i]) swap(a[i],a[n-i-1]);
//     }
//     int res=0;
//     for(int i=0;i<n-1;i++){
//         if(a[i]==a[i+1]) res++;
//     }
//     cout<<res<<endl;
// }



void solve()
{
    int n, m, x, k, q;
    cin >> n;
    vector<int> a(n);
    for (auto &t : a)
        cin >> t;
        
    vector<vector<int>> dp(n,vector<int>(2,0));
    for(int i=1;i<(n+1)/2;i++){
        dp[i][0]=min(dp[i-1][0]+(a[i]==a[i-1])+(a[n-i-1]==a[n-i]),dp[i-1][1]+(a[i]==a[n-i])+(a[i-1]==a[n-i-1]));
        dp[i][1]=min(dp[i-1][0]+(a[n-i-1]==a[i-1])+(a[i]==a[n-i]),dp[i-1][1]+(a[i]==a[i-1])+(a[n-i-1]==a[n-i]));
    }
    cout<<min(dp[(n+1)/2-1][0],dp[(n+1)/2-1][1])+(n%2==0 && a[n/2-1]==a[n/2])<<endl;
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