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

// dfs

// void solve()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<int> b(n + 1), w(n);
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> b[i];
//     }
//     vector<vector<pair<int, int>>> adj(n + 1);
//     for (int i = 0; i < m; i++)
//     {
//         int u, v, wt;
//         cin >> u >> v >> wt;
//         adj[u].push_back({v, wt});
//     }
//     int low = 1, high = 1e11;
//     int ans = -1;
//     function<bool(int, vector<int> &, int)> check = [&](int mid, vector<int> &dist, int p) -> bool
//     {
//         if (p == n) // we reached the destination
//             return true;
//         bool res = false;
//         for (auto &v : adj[p])
//         {
//             int node = v.first; // child node
//             int wt = v.second; // minimum batteries required to traverse this edge
//             if (dist[p] >= wt && mid >= wt) // can we traverse this edge or not
//             {
//                 long long newDist = dist[p] + b[node]; // new total number of batteries after traversing this edge
//                 if (newDist > dist[node]) // only proceed if we have found a better distance for that node
//                 {
//                     dist[node] = newDist;
//                     res = res || check(mid, dist, node);
//                 }
//             }
//         }
//         return res;
//     };

//     while (low < high)
//     {
//         int mid = (low + high) / 2;
//         vector<int> dist(n + 1, 0); // max batteries we can have at each node
//         dist[1] = b[1];
//         if (check(mid, dist, 1))
//         {
//             high = mid;
//             ans = mid;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//     }
//     cout << ans << "\n";
// }


// dijkstra
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> b(n + 1), w(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    int low = 1, high = 1e11;
    int ans = -1;

    function<bool(int)> checkDisjktra = [&](int mid) -> bool
    {
        vector<int> dist(n + 1, -INF);
        priority_queue<pair<int, int>> pq; // max heap
        pq.push({b[1], 1});                // {batteries, node}
        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int batteries = curr.first;
            int node = curr.second;
            if (node == n) // reached destination
            {
                return true;
            }
            for (auto &v : adj[node])
            {
                int child = v.first;
                int wt = v.second;
                if (batteries >= wt && mid >= wt) // can we traverse this edge or not
                {
                    int newBatteries = batteries + b[child]; // new total number of batteries after traversing this edge
                    if (newBatteries > dist[child]) 
                    {
                        dist[child] = newBatteries;
                        pq.push({newBatteries, child});
                    }
                }
            }
        }
        return dist[n] != -INF;
    };

    while (low < high)
    {
        int mid = (low + high) / 2;

        if (checkDisjktra(mid))
        {
            high = mid;
            ans = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
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