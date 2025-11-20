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

void solve() {
    int n, m;
    cin >> n >> m;

    int B = 0;
    while ((B + 1) * (B + 1) <= m) B++;

    int dpStart = min(n, B);
    int limit = m;
    int greedyScore = 0;

    for (int i = n; i > dpStart; --i) {
        int v = (limit / i) * i;
        if (v < i) {
            limit--;
        } else {
            limit = v - 1;
            greedyScore++;
        }
    }

    int maxDpScore = dpStart * 20 + 100;
    vector<int> dp(maxDpScore, -1);
    dp[0] = limit + 1;

    int maxS = 0;

    for (int i = dpStart; i >= 2; --i) {
        int lim = min(maxDpScore - 1, maxS + 20);
        vector<int> nextDp(lim + 1, -1);
        int nextMaxS = 0;

        for (int s = 0; s <= maxS; ++s) {
            if (dp[s] == -1) continue;

            int up = dp[s] - 1;
            if (up < i) continue;

            long long pw = 1;
            for (int k = 0; ; ++k) {
                if (k > 0) pw *= i;
                if (pw > up) break;

                int v = (up / pw) * pw;
                if (v < i) continue;

                if (s + k <= lim && v > nextDp[s + k]) {
                    nextDp[s + k] = v;
                    nextMaxS = max(nextMaxS, s + k);
                }
            }
        }

        dp = nextDp;
        maxS = nextMaxS;
    }

    int best = 0;
    for (int s = 0; s <= maxS; ++s) {
        if (dp[s] >= 2) best = max(best, s);
    }

    cout << best + greedyScore << "\n";
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
        solve();
    }

    return 0;
}