#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve()
{
    long long n, m, c = 0, j = 0, temp = 0, i = 0, k = 1;
    cin >> n;
    vector<long long> v;
    vector<long long> mp(n + 1, 0);

    for (long long i = 0; i < n; i++)
    {
        cin >> m;
        v.push_back(m);
    }


    if (v[0] > n)
    {
        cout << "NO" << endl;
        return;
    }


    for (i = n - 1; i >= 0; i--)
    {
        if (v[i] == k && mp[k] == 0)
        {
            mp[k] = i + 1;
            k++;
        }
        else if (v[i] > k)
        {
            while (k <= v[i])
            {
                mp[k] = i + 1;
                k++;
            }
        }
    }


    i = 0;
    while (i < n)
    {
        if (v[i] != mp[i + 1])
        {
            c = 1;
            break;
        }
        i++;
    }


    if (c == 0 && v[0] <= n)
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
