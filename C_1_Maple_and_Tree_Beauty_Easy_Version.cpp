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
int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }

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
int totalOnes,K;
int dfs(int i, int zeros, int totalUsed, vector<int> &val, vector<vector<int>> &dp) // total used are always constant for either i take one or zeros in every ith index
{
    if (i >= val.size())
    {
        return 0;
    }
    int remainingOnes=totalOnes-(totalUsed-(K-zeros));
    if (val[i] > remainingOnes && val[i] > zeros)
        return 0;
    if (dp[i][zeros] != -1)
        return dp[i][zeros];
    int takeOne = 0;
    if (remainingOnes >= val[i])
    {
        takeOne = 1 + dfs(i + 1, zeros, totalUsed+val[i], val, dp);
    }
    int takezero = 0;
    if (zeros >= val[i])
    {
        takezero = 1 + dfs(i + 1, zeros - val[i], totalUsed+val[i], val, dp);
    }
    return dp[i][zeros] = max(takeOne, takezero);
}
void Solve()
{
    int n, k;
    cin >> n >> k;
    K=k;
    totalOnes=n-k;
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    vector<int> labelCount;
    queue<int> q;
    q.push(1);
    bool flag = false;
    while (!q.empty())
    {
        int sz = q.size();
        labelCount.push_back(sz);
        while (sz--)
        {
            int node = q.front();
            q.pop();
            if (adj[node].size() == 0)
            {
                flag = true;
                break;
            }
            for (int ch : adj[node])
            {
                q.push(ch);
            }
        }
        if (flag)
            break;
    }
    vector<vector<int>> dp(labelCount.size() + 1, vector<int>(k + 1, -1));
    cout << dfs(0, k, 0,labelCount, dp) << endl;
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