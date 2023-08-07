#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    ll x, y, n, i, k, l;
    cin >> x >> y;
    n = (abs(x) + (abs(y))) * 2;
    k = abs(y);
    l = abs(x);
    cout << n << endl;
    if (x == 1 && y == 0)
    {
        cout << 1 << " " << 0;
    }
    else
    {
        if (x < 0)
        {
            for (i = 1; i <= k; i++)
            {
                cout << -i << " ";
            }
            for (i = k - 1; i > 0; i--)
            {
                cout << -i << " ";
            }
            for (i = l; i >0; i--)
            {
                cout<<-2<<" "<<-1<<" ";
            }
                cout << 0 << " ";
            
        }else if(y>0){
            for (i = 0; i <= l; i++)
            {
                cout << i << " ";
            }
            for (i = l - 1; i >= 0; i--)
            {
                cout << i << " ";
            }
            for (i = k; i >0; i--)
            {
                cout<<2<<" "<<1<<" ";
            }
                cout << 0 << " ";
        }
        else
        {
            for (i = 1; i <= k; i++)
            {
                cout << -i << " ";
            }
            for (i = k - 1; i > 0; i--)
            {
                cout << -i << " ";
            }
            for (i = 0; i <= l; i++)
            {
                cout << i << " ";
            }
            for (i = l - 1; i >= 0; i--)
            {
                cout << i << " ";
            }
        }
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