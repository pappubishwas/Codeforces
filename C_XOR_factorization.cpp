#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

void findLastTwo(int n, int k)
{
    int msb = 31 - __builtin_clz(n);
    vector<int> ans(k);
    int tight = k;
    for (int i = msb; i >= 0; i--)
    {
        if (n & (1LL << i))
        {
            int tightIdx = max(0LL,tight - 1);
            for (int j = 0; j < k; j++)
            {
                if (j == tightIdx)
                    continue;
                ans[j] += (1LL << i);
            }
            tight--;
            
        }
        else
        {
            for (int j = max(0LL,tight); j + 1 < k; j += 2)
            {
                ans[j] += (1LL << i);
                ans[j + 1] += (1LL << i);
            }
        }
    }
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
}

void Solve()
{
    int n, m, k, a, b;
    cin >> n >> k;

    if (k & 1)
    {
        for (int i = 0; i < k; i++)
            cout << n << " ";
        cout << "\n";
    }
    else
    {
        findLastTwo(n, k);
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