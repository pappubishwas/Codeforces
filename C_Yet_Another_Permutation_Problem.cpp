#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    ll n;
    cin >> n;
    vector<int> pap;
    unordered_map<int, int> mp;
    pap.push_back(1);
    int k = 2, count = 2, i = 0;
    while (i < n-1)
    {
        k = count;
        if (mp[k] != 0)
        {
            count++;
            continue;
        }
        else
        {
        
            while (k <= n)
            {

                pap.push_back(k);
                mp[k]++;
                k = k * 2;

                i++;
            }
            count++;
        }
        
    }
    for (i = 0; i < n; i++)
    {
        cout << pap[i] << " ";
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