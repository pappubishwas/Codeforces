#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    ll n, res = 0;
    cin >> n;
    vector<ll> fact;
    vector<ll> ans(n);
    for (ll i = 1; i <= n; ++i)
    {
        if (n % i == 0)
            fact.push_back(i);
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> ans[i];
    }
    fact.pop_back();
    
    for (ll i = 0; i < fact.size(); i++)
    {
       ll maxel = LLONG_MIN, minel = LLONG_MAX;
        ll k = fact[i], temp, p;
        for (int j = 0; j < n; j++)
        {
            temp = 0;
            p = 0;
            while (j < n && p < k)
            {
                temp += ans[j];
                j++;
                p++;
            }
            j--;
            maxel=max(maxel,temp);
            minel=min(minel,temp);
        }
        res=max(res,abs(maxel-minel));
    }
    cout<<res<<endl;
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