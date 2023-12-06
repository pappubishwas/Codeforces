#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve() {
    string s;
    cin >> s;
    char p = s[0], q = s[1];
    for (size_t i = 1; i <= 8; i++) {
        if (s[1] != '0' + i)
            cout << s[0] << static_cast<char>('0' + i) << endl;
    }
    for (size_t i = 1; i <= 8; i++) {
        if (s[0] != 'a' + i - 1)
            cout << static_cast<char>('a' + i - 1) << s[1] << endl;
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