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
int n, m, k;
int getDir(int dr, int dc) {
    if (dr == 1) return 0;  // Down
    if (dr == -1) return 1; // Up
    if (dc == 1) return 2;  // Right
    return 3;               // Left (dc == -1)
}
void dfs(int r, int c, int addr, int addc, vector<string> &g, vector<vector<int>> &visited)
{
    if (r >= n || c >= m || r < 0 || c < 0)
        return;
    int dir=getDir(addr,addc);
    if(visited[r][c] & (1LL<<dir)) return;
    visited[r][c] |=(1LL<<dir);
    if (g[r][c] == '.')
        dfs(r + addr, c + addc, addr, addc, g, visited);
    else
    {
        swap(addr, addc);
        if (g[r][c] == '/')
        {
            addr *= (-1);
            addc *= (-1);
        }
        dfs(r + addr, c + addc, addr, addc, g, visited);
    }
}

bool check(vector<string> &g, vector<vector<int>> &visited)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] != '.' && visited[i][j]==0)
            {
                return false;
            }
        }
    }
    return true;
}

void Solve()
{
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++)
        cin >> g[i];
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        vector<vector<int>> visited1(n, vector<int>(m, false)), visited2(n, vector<int>(m, false));
        dfs(i, 0, 0, 1, g, visited1);
        if (check(g,visited1))
        {
            string s = "W" + to_string(i + 1);
            ans.push_back(s);
        }
        dfs(i, m - 1, 0, -1, g, visited2);
        if (check(g,visited2))
        {
            string s = "E" + to_string(i + 1);
            ans.push_back(s);
        }
    }

    for (int i = 0; i < m; i++)
    {
        vector<vector<int>> visited1(n, vector<int>(m, false)), visited2(n, vector<int>(m, false));
        dfs(0, i, 1, 0, g, visited1);
        if (check(g, visited1))
        {
            string s = "N" + to_string(i + 1);
            ans.push_back(s);
        }
        dfs(n - 1, i, -1, 0, g, visited2);
        if (check(g, visited2))
        {
            string s = "S" + to_string(i + 1);
            ans.push_back(s);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
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