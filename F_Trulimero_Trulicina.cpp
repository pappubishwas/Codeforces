#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve()
{
    int n, k, m;
    cin >> n >> m >> k;
    int t = k;
    bool flag = true;
    if (m % k == 0)
    {
        // if ((k) % 2 == 0)
        // {
        //     for (int i = 0; i < n; i++)
        //     {
        //         for (int j = 0; j < m; j++)
        //         {
        //             cout << k << " ";
        //             if (i % 2 == 0)
        //                 k--;
        //             else
        //                 k++;
        //             if (i % 2 == 0 && k <= 0)
        //                 k = t;
        //             if (i % 2 == 1 && k > t)
        //                 k = 1;
        //         }
        //         if (i % 2 == 0)
        //             k = 1;
        //         else
        //             k = t;
        //         cout << endl;
        //     }
        // }
        // else
        // {
            k = 1;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << k << " ";
                    k++;
                    if ( k > t)
                        k = 1;
                }
                if(i%2==0) k=t;
                else k=1;
                cout << endl;
            }
        //}
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << k << " ";
                k--;
                if (k <= 0)
                    k = t;
            }
            cout << endl;
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