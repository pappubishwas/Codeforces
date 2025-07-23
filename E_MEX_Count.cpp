#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    ll n, k;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        /* code */
        int x;
        cin >> x;
        mp[x]++;
    }
    map<int, int> frq;
    int mex = 0;
    for (auto &[x, y] : mp)
    {
        if (x == mex)
        {
            mex++;
            frq[y]++;
        }
    }

    vector<int> a(n + 1, 0);
    a[n] = 1;

    for (int i = n - 1; i > n - mex; i--)
    {
        a[i] = a[i + 1] + 1;
    }
    a[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i])
            break;
        a[i] = a[i - 1] + frq[i];
    }

    for (auto &x : a)
    {
        cout << x << " ";
    }

    cout << endl;
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