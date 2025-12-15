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

int N = 200000;
int dp[301][301][301];
int mod=1e9+7;
int sol(int idx, int mx1, int mx2, vector<int> &v) // logest decreasing subsequence could not be 3
{
    if (idx >= v.size())
    {
        return 1;
    }
    if(dp[idx][mx1][mx2]!=-1) return dp[idx][mx1][mx2];
    int res = sol(idx+1,mx1,mx2,v)%mod; // skip current value
    int nmx1=mx1,nmx2=mx2;
    if(v[idx]>mx1) nmx1=v[idx]; // most max value is smaller than current value than update max
    if(v[idx]<mx1 && v[idx]>mx2) nmx2=v[idx]; // if curr value is smaller than max and bigger than 2nd max than update 2nd max

    if(v[idx]<mx2) return dp[idx][mx1][mx2]= res; // if current val is smaller than 2nd max value than we can't take this number
    res+=sol(idx+1,nmx1,nmx2,v)%mod;
    return dp[idx][mx1][mx2]=res%mod;
}

void Solve()
{
    int n, l, r, y, m, k;
    cin >> n;
    vector<int> pap(n);
    for (auto &x : pap)
        cin >> x;
    memset(dp,-1,sizeof(dp));    
    cout << sol(0, 0, 0, pap) << endl;
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