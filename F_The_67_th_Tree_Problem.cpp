#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve()
{
    int x, y;
    cin >> x >> y;
    int n = x + y;

    int odd = (x + y) - (x + y + 1) % 2;
    int even = (x + y) / 2;

    if (x > even || y > odd)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;

        int t = y; 

        if (n % 2)
            y--;
        else
            x--;
        if (x < 0 || y < 0)
        {
            cout << "NO" << endl;
            return;
        }

        for (int i = 2; y > 0; i++)
        {
            cout << 1 << " " << i << endl;
            y--;
        }

        int curr = 2;
        if (n % 2 == 0)
            t++;

        for (int i = t + 1; x > 0; i++)
        {
            cout << curr << " " << i << endl;
            curr++;
            x--;
        }
    }
}

int32_t main()
{
    auto begin = std::chrono::high_resolution_clock::now();
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
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}