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
const int mod = 998244353;
const int MOD = 1e9 + 7;
int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }
int fact[200001];
int powerl(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int inMod(int a)
{
    return powerl(a, mod - 2);
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> pap(n);
    vector<pair<int, int>> tan, ans;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> pap[i];
        tan.push_back({pap[i], i + 1});
        total += pap[i];
    }
    sort(tan.begin(), tan.end());
    if (2 * m > n)
    {
        cout << -1 << endl;
        return;
    }
    if (m == 0)
    {
        int l = 0, r = n - 1;
        while (l < r)
        {
            if (tan[n - 1].first > tan[l].first)
            {
                ans.push_back({tan[l].second, tan[n - 1].second});
                tan[n - 1].first -= tan[l].first;
            }
            else
            {
                break;
            }
            l++;
        }
        if (l == r)
        {
            cout << -1 << endl;
        }
        else
        {
            while (l < r)
            {
                ans.push_back({tan[l].second, tan[l + 1].second});
                l++;
            }

            cout << ans.size() << endl;
            for (auto &t : ans)
            {
                cout << t.first << " " << t.second << endl;
            }
        }
    }
    else
    {
        int r = n - 2 * m;
        for (int i = 0; i < r; i++)
        {
            ans.push_back({tan[i].second, tan[i + 1].second});
        }
        while (m--)
        {
            ans.push_back({tan[n - 1].second, tan[r].second});
            n--;
            r++;
        }
        cout << ans.size() << endl;
        for (auto &t : ans)
        {
            cout << t.first << " " << t.second << endl;
        }
    }
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