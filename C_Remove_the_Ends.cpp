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
// int dp[200005][2];

// int recur(int idx,bool cantake,vector<int>& pap){
//     if(idx>=pap.size()) return 0;
//     if(dp[idx][cantake]!=-1) return dp[idx][cantake];
//     int res=0;
//     if(cantake){
//         if(pap[idx]>0){
//             res=pap[idx]+recur(idx+1,cantake,pap);
//         }else{
//             int skip=recur(idx+1,cantake,pap);
//             int taken=abs(pap[idx])+recur(idx+1,false,pap);
//             res=max(skip,taken);
//         }
//     }else{
//         if(pap[idx]<0) res=abs(pap[idx]);
//         res+=recur(idx+1,cantake,pap);
//     }
//     return dp[idx][cantake]= res;
// }

void solve()
{
    int n, m, k;
    cin >> n ;
    vector<int> pap(n);
    for(auto& t:pap) cin>>t;
    // memset(dp,-1,sizeof(dp));
    // int res=recur(0,true,pap);
    // cout<<res<<endl;
    int psum=0,nsum=0;
    for(int i=0;i<n;i++){
        if(pap[i]>0) psum+=pap[i];
        else nsum-=pap[i];
    }
    int res=max(nsum,psum);
    int cpsum=0,cnsum=0;
    for(int i=0;i<n;i++){
        if(pap[i]>0) cpsum+=pap[i];
        else cnsum-=pap[i];
        res=max(res,cpsum+nsum-cnsum);
    }
    cout<<res<<endl;
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



// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int MOD = 998244353;

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> pap(n);
//     for (auto &x : pap) cin >> x;

//     vector<vector<int>> dp(n + 1, vector<int>(2, 0)); 
//     // dp[i][0] => can't take; dp[i][1] => can take

//     for (int idx = n - 1; idx >= 0; idx--) {
//         // when cantake = true
//         if (pap[idx] > 0)
//             dp[idx][1] = pap[idx] + dp[idx + 1][1];
//         else {
//             int skip = dp[idx + 1][1];
//             int taken = abs(pap[idx]) + dp[idx + 1][0];
//             dp[idx][1] = max(skip, taken);
//         }

//         // when cantake = false
//         dp[idx][0] = dp[idx + 1][0];
//         if (pap[idx] < 0)
//             dp[idx][0] = abs(pap[idx]) + dp[idx + 1][0];
//     }

//     cout << dp[0][1] << "\n";
// }

// int32_t main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--) solve();
// }
