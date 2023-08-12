#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve()
{
    int n, i, j, k;
    cin >> n;
    vector<int> v;
    for (i = 0; i < n; i++)
    {
        cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    vector<int> v1;
    vector<int> v2;
    v1.push_back(v[0]);
    for (i = 1; i < n; i++)
    {
        if (v1[0] == v[i])
            v1.push_back(v[i]);
        else
        {
            v2.push_back(v[i]);
        }
    }
    if (v2.size() == 0)
        cout << -1 << endl;
    else
    {
        cout<<v1.size()<<" "<<v2.size()<<endl;
        for (i = 0; i < v1.size(); i++)
        {
            cout << v1[i] << " ";
        }
        cout << endl;
        for (i = 0; i < v2.size(); i++)
        {
            cout << v2[i] << " ";
        }
        cout << endl;
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