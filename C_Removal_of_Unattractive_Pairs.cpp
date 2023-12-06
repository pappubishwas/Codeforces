#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    string s;
    ll n;
    cin >> n;
    cin >> s;
    vector<int> fre(26, 0);
    for (size_t i = 0; i < n; i++)
    {
        fre[s[i] - 'a']++;
    }
    int t = -1, indx = -1;
    for (size_t i = 0; i < 26; i++)
    {
        if (fre[i] > 0)
        {
            if (t < fre[i])
            {
                t = fre[i];
            }
        }
    }
    if (t < (n - t))
        cout << n % 2 << endl;
    else
        cout << t - (n - t) << endl;
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