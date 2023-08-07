#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    ll n, j = 0, k, count = 0;
    cin >> n;
    vector<ll> myset;
    for (ll i = 0; i < n; i++)
    {
        cin >> k;
        myset.push_back(k);
    }
    sort(myset.begin(), myset.end());
    for (auto i = myset.begin(); i != myset.end(); i++)
    {
        if ((*i) != j)
        {
            j++;
            count = count + (*i) - j;
        }
    }
    cout<<count<<endl;
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