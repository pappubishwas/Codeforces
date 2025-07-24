#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve()
{
    ll n, k;
    cin >> n;
    vector<ll> a(n), p(n), s(n);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = std::lcm(p[i], s[i]);
    }
    int g = a[0];
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        g = std::gcd(g, a[i]);
        if (g != p[i])
        {
            ans = false;
            break;
        }
    }
    g = a[n - 1];
    if (ans)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            g = std::gcd(g, a[i]);
            if (g != s[i])
            {
                ans = false;
                break;
            }
        }
    }
    if (ans)
    {
        cout << "YES" << endl;
    }
    else
    {
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