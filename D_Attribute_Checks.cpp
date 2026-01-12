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
    int m, n;
    cin >> n >> m;
    vector<int> pap(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pap[i];
    }
    vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
    dp[0][0]=0;
    int total = 0;
    vector<int> str, intell;
    for (int i = 0; i < n; i++)
    {
        if (pap[i] < 0)
            str.push_back(-pap[i]);
        else if (pap[i] > 0)
            intell.push_back(pap[i]);
        else
        {
            sort(str.begin(), str.end());
            sort(intell.begin(), intell.end());
            total++;
            for (int in = 0; in <= total; in++)
            {
                if (in != 0)
                {                                               // current one is for intelligent
                    int inCount = in - 1, stCount = total - in; // before current point,number of intelligent count and number of strength count
                    int val = (upper_bound(intell.begin(), intell.end(), inCount) - intell.begin()) + (upper_bound(str.begin(), str.end(), stCount) - str.begin());
                    dp[total][in] = max(dp[total][in], dp[total - 1][in - 1] + val);
                }
                if (in < total)
                {                                               // current one is for strength
                    int inCount = in, stCount = total - in - 1; // before current point,number of intelligent count and number of strength count
                    int val = (upper_bound(intell.begin(), intell.end(), inCount) - intell.begin()) + (upper_bound(str.begin(), str.end(), stCount) - str.begin());
                    dp[total][in] = max(dp[total][in], dp[total - 1][in] + val);
                }
            }
            str.clear();
            intell.clear();
        }
    }
    sort(str.begin(), str.end());
    sort(intell.begin(), intell.end());
    int ans=0;
    for (int in = 0; in <= m; in++)
    {                                               // current one is for intelligent
            int inCount = in, stCount = m - in; // before current point,number of intelligent count and number of strength count
            int val = (upper_bound(intell.begin(), intell.end(), inCount) - intell.begin()) + (upper_bound(str.begin(), str.end(), stCount) - str.begin());
            ans = max(ans, dp[m][in] + val);
        
    }
    cout<<ans<<endl;
}
int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    return 0;
}