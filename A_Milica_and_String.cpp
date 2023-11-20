#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    int n, k, b = 0, a = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B')
            b++;
    }
    if (k == b)
        cout << 0 << endl;
    else
    {
        cout << 1 << endl;
        if (k > b)
        {
            int t = k - b;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'A')
                    a++;

                if (t == a)
                {
                    cout << i + 1 << " "
                         << "B" << endl;
                    break;
                }
            }
        }
        else
        {
            int t = b - k;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'B')
                    a++;
                if (t == a)
                {
                    cout << i + 1 << " "
                         << "A" << endl;
                    break;
                }
            }
        }
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