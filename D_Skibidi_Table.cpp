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

void Solve()
{
    int n, q;
    cin >> n >> q;

    auto recover = [&](auto self, int n, int x, int y) -> int
    {
        if (n == 0)
            return 0LL;
        int d = 1 << (n - 1);
        if (x < d && y < d)
        {
            return self(self, n - 1, x, y);
        }
        else if (x >= d && y >= d)
        {
            return self(self, n - 1, x - d, y - d) + d * d;
        }
        else if (x >= d && y < d)
        {
            return self(self, n - 1, x - d, y) + 2 * d * d;
        }
        else
        {
            return self(self, n - 1, x, y - d) + 3 * d * d;
        }
    };

    auto find = [&](auto self, int n, int x) -> pair<int, int>
    {
        if (n == 0)
        {
            return make_pair(0, 0);
        }
        int d = 1 << (n - 1);
        int y = d * d;
        if (x < y)
        {
            return self(self, n - 1, x);
        }
        else if (x < 2 * y)
        {
            auto pi = self(self, n - 1, x - y);
            pi.first += d;
            pi.second += d;
            return pi;
        }
        else if (x < 3 * y)
        {
            auto pi = self(self, n - 1, x - 2 * y);
            pi.first += d;
            return pi;
        }
        else
        {
            auto pi = self(self, n - 1, x - 3 * y);
            pi.second += d;
            return pi;
        }
    };

    while (q--)
    {
        string type;
        cin >> type;
        int x, y;
        if (type == "->")
        {
            cin >> x >> y;
            x--;
            y--;
            cout << recover(recover,n, x, y) + 1 << endl;
        }
        else
        {
            cin >> x;
            x--;
            auto pi = find(find,n, x);
            cout << pi.first + 1 << " " << pi.second + 1 << endl;
        }
    }
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
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}