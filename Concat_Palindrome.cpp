#include <bits/stdc++.h>
#define lng long long
using namespace std;

void solve()
{
    lng n, m, t = 0;
    string x, y, str;
    cin >> n >> m >> x >> y;
    map<char, int> ptr;
    int i;
    if (m > n)
    {
        t = n;
        n = m;
        m = t;

        str = y;
        y = x;
        x = str;
    }

    for (i = 0; i < n; i++)
    {
        ptr[x[i]] += 1;
    }

    for ( i = 0; i < m; i++)
    {
        ptr[y[i]] -= 1;
    }

    int pt = 1, q = 0;
    for (auto p : ptr)
    {
        if (p.second < 0)
        {
            pt = 0;
            break;
        }
        if (p.second % 2 == 0)
        {
            continue;
        }
        if (q)
        {
            pt = 0;
        }
        else
        {
            q = 1;
        }
    }
    if (pt)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    lng t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}