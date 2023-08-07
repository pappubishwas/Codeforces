#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    ll a, b, n, m, k, t;
    cin >> a >> b;
    cin >> n >> m;
    k = (a * m) / (m + 1);
    if (k >= b)
        cout << b * n << endl;
    else
    {
        if (n <= m)
            if(a<=b) cout << n * a << endl;
            else cout << n * b << endl;
        else
        {
            if (b < a)
            {
                t = (n / (m + 1));
                cout << (t * m * a + (n - t * m - t) * b)<<endl;
            }
            else
            {
                t = (n / (m + 1));
                cout << (t * m * a + (n - t * m - t) * a)<<endl;
            }
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