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
const int MOD = 1e9 + 7;
int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }
int powerl(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
int inMod(int a)
{
    return powerl(a, MOD - 2);
}

void Solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    int res = 1 + adj[1].size();
    q.push(1);
    vector<bool> visited(n + 1, false);
    visited[1] = true;
    vector<int> layerSz(n+1,0);
    int level=1;
    layerSz[0]=1;
    while (!q.empty())
    {
        int sz = q.size();
        res = max(res, sz);
        int total=0;
        int child = 0;
        while (sz--)
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                    total++;
                }
            }
            int ch = adj[u].size();
            child = max(child, ch);
        }
        layerSz[level]=total;
        level++;
        res = max(res, child);
    }
    cout << res << endl;
    vector<vector<int>> gr(res + 1);
    vector<int> color(n + 1,0);
    queue<int> q1;
    q1.push(1);
    visited.assign(n + 1, false);
    visited[1] = true;
    color[1] = 1;
    deque<int> prevPar;
    prevPar.push_back(1);
    level=1;
    while (!q1.empty())
    {
        int sz=q1.size();
        set<int> temp;
        for(int i=1;i<=min(layerSz[level]+1,res);i++){
            temp.insert(i);
        }
        deque<int> currColors;
        int last = 0;
        while (sz--)
        {
            int u = q1.front();
            q1.pop();
            for (int v : adj[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q1.push(v);
                    int chosen_color = -1;

                    if (!prevPar.empty() && prevPar.front() != color[u] && temp.count(prevPar.front()))
                    {
                        chosen_color = prevPar.front();
                        prevPar.pop_front();
                    }
                    else if (!prevPar.empty() && prevPar.back() != color[u] && temp.count(prevPar.back()))
                    {
                        chosen_color = prevPar.back();
                        prevPar.pop_back();
                    }
                    else
                    {
                        if (*temp.begin() != color[u])
                        {
                            chosen_color = *temp.begin();
                        }
                        else
                        {
                            if (*prev(temp.end()) != color[u])
                            {
                                chosen_color = *prev(temp.end());
                            }
                            else
                            {
                                color[v] = color[last];
                                color[last] = *prev(temp.end());
                                chosen_color = *prev(temp.end());
                            }
                        }
                    }
                    if (color[v] == 0)
                        color[v] = chosen_color;

                    if (chosen_color == -1)
                        continue;
                    temp.erase(chosen_color);
                    currColors.push_back(chosen_color);
                    if (last == 0)
                        last = v;
                }
            }
        }
        level++;
        prevPar = currColors;
    }
    
    for (int i = 1; i <= n; i++)
    {
        gr[color[i]].push_back(i);
    }
    for (auto &g : gr)
    {
        if (g.size() == 0)
            continue;
        cout << g.size() << " ";
        for (int node : g)
            cout << node << " ";
        cout << endl;
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




