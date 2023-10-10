#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    if (n <= 6 || n == 9)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        if (n % 3 == 0)
        {
            cout << 1 << " " << 4 << " " << n - 5 << endl;
        }
        else
            cout << 1 << " " << 2 << " " << n - 3 << endl;
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