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
    int zero = 0, one = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (s[i] == '0')
            zero++;
        else
            one++;
    }
    if (zero > one)
        cout << "YES" << endl;
    else
    {
        for (size_t i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1])
            {
                cout << "YES" << endl;
                return;
            }
        }
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