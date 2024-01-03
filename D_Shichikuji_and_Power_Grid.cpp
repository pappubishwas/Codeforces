#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N], sz[N];

void make(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find(int v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = find(parent[v]);
}

void Union(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u != v)
    {
        if (sz[u] < sz[v])
            swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
    }
}
int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> cities(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> cities[i].first >> cities[i].second;
    }
    vector<int> c(n + 1), k(n + 1);
    for (int i = 1; i <=n; i++)
        cin >> c[i];
    for (int i = 1; i <=n; i++)
        cin >> k[i];
    vector<pair<long long, pair<int, int>>> edges;
    for (int i = 1; i <= n; i++)
    {
        edges.push_back({c[i], {0, i}});
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int dist = abs(cities[i].first - cities[j].first) +abs( cities[i].second - cities[j].second);
            long long cost = dist * 1LL * (k[i] + k[j]);
            edges.push_back({cost, {i, j}});
        }
    }
    sort(begin(edges), end(edges));
    for (int i = 1; i <= n; i++)
        make(i);
    long long total_cost = 0;
    vector<int> power_station;
    vector<pair<int, int>> connections;
    for (auto &edge : edges)
    {
        int u, v, wt;
        wt = edge.first;
        u = edge.second.first;
        v = edge.second.second;
        if (find(u) == find(v))
            continue;
        Union(u, v);
        total_cost += wt;
        if (u == 0 || v == 0)
            power_station.push_back(max(u, v));
        else
            connections.push_back({u, v});
    }
    cout << total_cost << endl;
    cout<<power_station.size()<<endl;
    sort(power_station.begin(),power_station.end());
    for(auto pt:power_station){
        cout<<pt<<" ";
    }
    cout<<endl;
    cout<<connections.size()<<endl;
    for(auto &connection: connections){
        cout<<connection.first<<" "<<connection.second<<endl;
    }
}