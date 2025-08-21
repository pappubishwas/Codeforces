#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, c, k;
    cin >> n;
    string s;

    vector<int> a(n), b(n);
    ll mx = INT_MIN, mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<pair<ll, ll>> res;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            swap(a[i], b[i]);
            ans++;
            res.push_back({3, i + 1});
        }
    }
    bool swapped;

    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = true;
                res.push_back({1,j+1});
                ans++;
            }
        }

        if (!swapped)
            break;
    }

    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (b[j] > b[j + 1])
            {
                swap(b[j], b[j + 1]);
                swapped = true;
                res.push_back({2,j+1});
                ans++;
            }
        }

        if (!swapped)
            break;
    }
    cout << ans << endl;
    for(auto it: res){
        cout<<it.first<<" "<<it.second<<endl;
    }
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
