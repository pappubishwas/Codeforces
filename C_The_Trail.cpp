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

int fillgrid(int i, char dir, int n, int m, vector<vector<int>> &pap)
{
    int sum = 0;
    if (dir == 'D')
    {
        int col = 1;
        while (col <= m)
        {
            sum += pap[i][col];
            col++;
        }
    }
    else
    {
        int row = 1;
        while (row <= n)
        {
            sum += pap[row][i];
            row++;
        }
    }
    return -sum;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<int>> pap(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> pap[i][j];
        }
    }
    int row = 1, col = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'D')
        {
            pap[row][col] = fillgrid(row, s[i], n, m, pap);
            row++;
        }
        else
        {
            pap[row][col] = fillgrid(col, s[i], n, m, pap);
            col++;
        }
    }
    pap[row][col] = fillgrid(row,'D', n, m, pap);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout<< pap[i][j]<<" ";
        }
        cout<<endl;
    }
    //cout<<endl;
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
