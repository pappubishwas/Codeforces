#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    ll a, b, c, d1, d2;
    int k = 0;
    cin >> a >> b >> c;
     d1 = a - b;
     d2 = b - c;
    if ((abs(a-b) == abs(b-c)))
        cout << "YES" << endl;
    else if (d1 > 0 && d2 < 0)
    {
        int i = 2;
        while (i <= 9 && b<c)
        {
            b = b * i;
            d1 = a - b;
            d2 = b - c;
            if ((abs(d1) == abs(d2)))
            {
                k = 1;
                break;
            }
            i++;
        }
        if (k == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else if (d1 < 0 && d2 > 0)
    {
        int i = 2;
        while (i <= 9)
        {
            a = a * i;
            d1 = a - b;
            d2 = b - c;
            if ((abs(d1) == abs(d2)))
            {
                k = 1;
                break;
            }
            i++;
        }
        if (k == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
    {
        int i = 2;
        while (i <= 9)
        {
            c = c * i;
            d1 = a - b;
            d2 = b - c;
            if ((abs(d1) == abs(d2)))
            {
                k = 1;
                break;
            }
            i++;
        }
    
        if (k == 1)
            cout << "YES" << endl;
        else
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