#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve()
{
    ll n, k = 0, c = 0, l = 0, j;
    cin >> n;
    string p;
    cin >> p;
    if (p[0] == '0')
        k = 1;
    for (ll i = 1; i < n; i++)
    {
        if (p[i] != '0')
            k = 0;
        else if (k != 0)
            k++;
        else if (p[i] == '0' && i+1<n)
        {
            if ((p[i - 1] == '+' && p[i + 1] == '-') || (p[i - 1] == '-' && p[i + 1] == '+'))
                c++;
            else if (p[i + 1] != '0')
                continue;
            else
            {
                for (j = i + 1; j < n; j++)
                {
                    if (p[j] != '0')
                    {
                        if (p[i - 1] != p[j])
                            c++;

                        i = j;
                        break;
                    }
                }
                if (i == n)
                {
                    break;
                }
            }
        }
    }
    cout << k + c << endl;
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
