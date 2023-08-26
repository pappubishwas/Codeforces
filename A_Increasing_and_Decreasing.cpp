#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve()
{
    ll x, y, n;
    cin >> x >> y >> n;
    if ((y - x) < n)
        cout << -1 << endl;
    else
    {
        ll i = 1, a[n], k = n - 2, c = 0;
        a[n - 1] = y;
        while (k >= 0)
        {
            if (k == 0)
                a[k] = x;
            else
                a[k] = a[k + 1] - i;
            if ((a[k + 1] - i) < x)
            {
                c = 1;
                break;
            }
            i++;
            k--;
        }
        if (c == 1)
            cout << -1 << endl;
        else
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[j] << " ";
            }
            cout << endl;
        }
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
