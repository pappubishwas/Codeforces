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

int dp[75][75][2]; 

int ans(string &s, int idx, int k)
{
    if (k <= 0)
        return 0;

    if (idx >= (int)s.size())
        return k;

    int current_bit = s[idx] - '0';
    if(dp[idx][k][current_bit] != -1) return dp[idx][k][current_bit];

    int ones = count(s.begin() + idx, s.end(), '1');
    if (ones == 1)
        return k;

    int res = ans(s, idx + 1, k);
    int take = 0;

    if (s[idx] == '1')
    {
        int i = idx;
        while (i < (int)s.size() && s[i] == '1')
            i++;

        if (i < (int)s.size())
            s[i] = '1';

        take = (i - idx) + ans(s, i, k - 1);
        
        if (i < (int)s.size())
            s[i] = '0';
    }

    return dp[idx][k][current_bit] = max(res, take);
}

void Solve()
{
    int n, k;
    cin >> n >> k;

    if (k >= 30) 
    {
        cout << __builtin_popcountll(n) + k - 1 << endl;
        return;
    }

    string s = bitset<64>(n).to_string();
    s.erase(0, s.find_first_not_of('0'));
    reverse(s.begin(), s.end());

    
    memset(dp, -1, sizeof(dp));
    
    cout << ans(s, 0, k) << endl;
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