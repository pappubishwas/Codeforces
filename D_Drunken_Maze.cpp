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
    int n, m, k;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++)
        cin >> g[i];
    int si, sj, ei, ej;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 'S')
            {
                si = i;
                sj = j;
            }
            if (g[i][j] == 'T')
            {
                ei = i;
                ej = j;
            }
        }
    }
    vector<vector<int>> dir{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // d r u l
    vector<vector<vector<int>>> dist(n * m, vector<vector<int>>(4, vector<int>(4, INF)));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, -1, 0, si, sj});
    dist[si*m+sj][0][0] = 0;
    while (!pq.empty())
    {
        auto curr = pq.top();
        int cost = curr[0];
        int direction = curr[1];
        int steps = curr[2];
        int i = curr[3];
        int j = curr[4];
        pq.pop();
        if (i == ei && j == ej)
        {
            cout << cost << endl;
            return;
        }
        if (direction!=-1 && cost > dist[i*m+j][direction][steps])
            continue;
        for (int d = 0; d <= 3; d++)
        {
            int ni = i + dir[d][0];
            int nj = j + dir[d][1];
            if (ni >= n || ni < 0 || nj >= m || nj < 0 || g[ni][nj] == '#')
                continue;
            if (d == direction)
            {
                if (steps == 3)
                {
                    if (cost + 3 < dist[ni*m+nj][d][2])
                    {
                        dist[ni*m+nj][d][2]= cost + 3;
                        pq.push({cost + 3, d, 2 , ni, nj});
                    }
                }
                else if (cost + 1 < dist[ni*m+nj][d][steps+1])
                {
                    dist[ni*m+nj][d][steps+1] = cost + 1;
                    pq.push({cost + 1, d, steps + 1, ni, nj});
                }
            }
            else
            {
                if (cost + 1 < dist[ni*m+nj][d][1])
                {
                    dist[ni*m+nj][d][1]= cost + 1;
                    pq.push({cost + 1, d, 1, ni, nj});
                }
            }
        }
    }
    cout << -1 << endl;
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