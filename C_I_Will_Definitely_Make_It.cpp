#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll start = a[k - 1];
    set<ll> s(a.begin(), a.end());
    bool res = true, flag = true;

    ll currTime = 0;
    for (auto &el : s)
    {
        if (flag && el != start)
        {
            continue;
        }
        else if (flag)
        {
            flag = false;
            continue;
        }
        if (!flag)
        {
            currTime += el - start;
            
            if (currTime > start)
            {
                res = false;
                break;
            }
            start = el;
        }
    }
    if (res)
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