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
vector<int> dp(501); // pre compute all nc2 values
void Solve()
{
    int n, m, k;
    cin >> k;
    vector<pair<int, int>> ans;
    int x1=1,y1=0;
    //cout<<dp[500]<<"\n";
    while(k>0){
        auto it=lower_bound(dp.begin(),dp.end(),k); // find the largest nc2 value less than or equal to k
        int idx=it-dp.begin();
        if(dp[idx]>k) idx--; // if it is greater than k we need to decrement idx by 1
        int val=dp[idx];
        for(int i=0;i<idx;i++){
            ans.push_back({x1,y1++}); // add idx points in the same x coordinate
        }
        x1++; // increment x coordinate for next set of points and y always starts from next where it previoyusly left off
        k-=val;
    }
    cout<<ans.size()<<"\n";
    for(auto p:ans){
        cout<<p.first<<" "<<p.second<<"\n";
    }
}

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=500;i++){
        dp[i]=(i*(i-1))/2;
    }
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}