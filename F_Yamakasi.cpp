#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll answer(vector<ll> v, ll s)
{
    ll n=v.size();
    ll p[n+1];
    p[0]=0;
    for(int i=0;i<n;i++){
        p[i+1]=p[i]+v[i];
    }
    
    map<ll,ll> m;
    m[0]++;
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=m[p[i]-s];
        m[p[i]]++;
    }
    return ans;
}

void solve()
{
    ll n, c, k, l, r, s, x;
    cin >> n >> s >> x;

    vector<ll> a(n), b;
    ll mx = INT_MIN, mn = INT_MAX, ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] > x)
        {
            ans += answer(b, s);
            b.clear();
        }
        else
        {
            b.push_back(a[i]);
        }
    }
    ans += answer(b, s);
    b.clear();
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= x)
        {
            ans -= answer(b, s);
            b.clear();
        }
        else
        {
            b.push_back(a[i]);
        }
    }
    ans -= answer(b, s);
    b.clear();

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
