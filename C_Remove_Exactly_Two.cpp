#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define INF (int)1e18
#define mp make_pair
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }

int binaryLength(int n)
{
    return 64 - __builtin_clzll(n);
}
int mod = 998244353;

class DSU
{
public:
    vector<int> rank;
    vector<int> parent;
    DSU(int n)
    {
        rank.assign(n + 1, 0);
        parent.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return;

        if (rank[px] > rank[py])
        {
            parent[py] = px;
        }
        else if (rank[px] < rank[py])
        {
            parent[px] = py;
        }
        else
        {
            parent[px] = py;
            rank[py]++;
        }
    }
};

void solve()
{
    // int n, m, k, m1, m2;
    // cin >> n;
    // vector<pair<int, int>> edges1;
    // DSU g(n);
    // vector<set<int>> adj(n + 1);
    // for (int i = 0; i < n - 1; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     edges1.push_back({u, v});
    //     adj[v].insert(u);
    //     adj[u].insert(v);
    // }

    // int f1 = 0, sz1 = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (adj[i].size() > sz1)
    //     {
    //         sz1 = adj[i].size();
    //         f1 = i;
    //     }
    // }
    // int f2 = -1,sz2=0;
    // for (int i = 1; i <= n; i++)
    // {
    //     if(f1==i) continue;
    //     if (adj[i].size() > sz2)
    //     {
    //         if(adj[f1].find(i)==adj[f1].end()){
    //             sz2=adj[i].size();
    //             f2=i;
    //         }
    //     }
    // }
    // if(f2==-1){
    //     if(f1==1) f2=2;
    //     else f2=1;
    // }
    // cout<<f1<<f2<<endl;
    // for (int i = 0; i < n - 1; i++)
    // {
    //     int u = edges1[i].first;
    //     int v = edges1[i].second;
    //     if (u == f1 || u == f2 || v == f1 || v == f2)
    //         continue;
    //     g.Union(u, v);
    // }
    // set<int> p;
    // for (int i = 1; i <= n; i++)
    //     p.insert(g.find(i));
    // int ans = p.size() - 2;
    // cout << ans << endl;

    int n;
	cin >> n;
	set<pair<int,int>> edges;
	vector<int> deg(n+1);
	for(int i=0;i<n-1;i++) {
		int a,b;
		cin >> a >> b;
		edges.insert(mp(a,b));
		edges.insert(mp(b,a));
		deg[a]++;
		deg[b]++;
	}
	int ans = 0;
	vector<pair<int,int>> b;
	for(int i=0;i<n;i++) {
		b.push_back(mp(deg[i+1], i+1));
	}
	sort(b.begin(), b.end(), greater<pair<int,int>>());
	for(int i=0;i<n;i++) {
		for(int j = i+1; j < n; j++) {
			if(edges.find(mp(b[i].second, b[j].second)) == edges.end()) {
				ans = max(ans, b[j].first + b[i].first - 1);
				break;
			}
		}
	}
 
	for(auto x : edges) {
		ans = max(ans, deg[x.first] + deg[x.second] - 2);
	}
	cout << ans <<endl;
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
