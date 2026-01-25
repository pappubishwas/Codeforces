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
    int n, q;
    cin >> n >> q;
    vector<int> pap(n + 1), pref(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> pap[i];
        pref[i] = pref[i - 1] + pap[i];
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int ftb = l / n;
        int ltb = r / n;
        int sl = l % n, er = r % n;
        int ans = 0;
        if (ftb == ltb)
        {
            if (ftb == 0)
            {
                ans = pref[r + 1] - pref[l];
            }
            else
            {
                int d = n - ftb;
                // if (sl < d)
                // {
                //     ans += pref[min(n, er + d + 1)] - pref[sl + ftb];
                //     if (er >= d)
                //     {
                //         ans += pref[er - d + 1];
                //     }
                // }
                // else
                // {
                //     ans += pref[er - d + 1] - pref[sl - d];
                // }

                if (sl < d)
                {
                    if (er < d)
                    {
                        ans += pref[ftb + er + 1] - pref[sl + ftb];
                    }
                    else
                    {
                        ans += pref[n] - pref[sl + ftb];
                        ans += pref[er - d + 1];
                    }
                }
                else
                {
                    ans += pref[er - d + 1] - pref[sl - d];
                }
            }
        }
        else
        {
            ans += (ltb - ftb - 1) * (pref[n]);
            if (ftb == 0)
            {
                ans += pref[n] - pref[l];
            }
            else
            {
                int d = n - ftb;
                if (sl < d)
                {
                    ans += pref[n] - pref[sl + ftb];
                    ans += pref[n - d];
                }
                else
                {
                    ans += pref[ftb] - pref[sl - d];
                }
            }
            int d = n - ltb;
            if (er >= d)
            {
                ans += pref[n] - pref[ltb];
                ans += pref[er - d + 1];
            }
            else
            {
                ans += pref[ltb + er + 1] - pref[ltb];
            }
        }
        cout << ans << endl;
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