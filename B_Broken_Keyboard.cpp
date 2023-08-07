#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    int p;
    cin >> p;
    string s;
    cin >> s;
    int i = 0, k = 0;
    while (s[i] != '\0' && s[i + 1] != '\0' && s[i + 2] != '\0')
    {
        if (s[i + 1] != s[i + 2])
        {
            k = 1;
            break;
        }
        i = i + 3;
    }
    if ((k == 0 && (s[i] == '\0')) || (k == 0 && s[i + 1] == '\0'))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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