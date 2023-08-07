#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve()
{
    ll n, m, c = 0, t = 0, k = 0;
    cin >> n >> m;
    string p, q;
    cin >> p >> q;
    if (p[n - 1] == q[m - 1])
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (p[i] == p[i + 1])
            {
                c = 1;
                break;
            }
        }
        if (c != 1)
        {
            for (int i = 0; i < m - 1; i++)
            {
                if (q[i] == q[i + 1])
                {
                    c = 1;
                    break;
                }
            }
        }
        if (c != 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (p[i] == p[i + 1])
            {
                c++;
                if (c == 2)
                    break;
            }
        }
        if (c != 2)
        {
            for (int i = 0; i < m - 1; i++)
            {
                if (q[i] == q[i + 1])
                {
                    c++;
                    if (c == 2)
                        break;
                }
            }
        }
        if (c != 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
