#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve()
{
    ll n, i, j, k, temp, sum = 0;
    cin >> n;
    vector<vector<ll>> v;
    vector<ll> fr;
    vector<ll> se;
    for (i = 0; i < n; i++)
    {
        cin >> k;
        vector<ll> t;
        for (j = 0; j < k; j++)
        {
            cin >> temp;
            t.push_back(temp);
        }
        sort(t.begin(), t.end());
        fr.push_back(t[0]);
        se.push_back(t[1]);
        v.push_back(t);
    }

    sort(fr.begin(), fr.end());
    sort(se.begin(), se.end());
    sum += fr[0];
    for (i = 1; i < n; i++)
    {
        sum += se[i];
    }
    cout << sum << endl;
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