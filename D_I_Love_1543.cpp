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

int ans(int row1, int col1, int row2, int col2, vector<string> &grid)
{
    string s = "";
    int r1 = row1, r2 = row2, c1 = col1, c2 = col2;
    while (c1 < c2)
    {
        s += grid[r1][c1];
        c1++;
    }
    while (r1 < r2)
    {
        s += grid[r1][c1];
        r1++;
    }
    while (col1 < c1)
    {
        s += grid[r1][c1];
        c1--;
    }
    while (row1 < r1)
    {
        s += grid[r1][c1];
        r1--;
    }
    if (s.size() < 4)
        return 0LL;
    int count = 0;
    int n = s.size();
    for (int i = 0; i < n + 4LL; i++)
    {
        if (s[i % n] == '1' && s[(i + 1) % n] == '5' && s[(i + 2) % n] == '4' && s[(i + 3) % n] == '3')
        {
            count++;
            s[i % n] = '0';
            s[(i + 1) % n] = '5';
            s[(i + 2) % n] = '4';
            s[(i + 3) % n] = '3';
        }
    }
    return count;
}

void solve()
{
    int n, m, x, k;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    int r1 = 0, c1 = 0, r2 = n - 1, c2 = m - 1, res = 0;
    while (r1 <= r2 && c1 <= c2)
    {
        res += ans(r1, c1, r2, c2, grid);
        r1++;
        c1++;
        r2--;
        c2--;
    }
    cout<<res;
    cout << endl;
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