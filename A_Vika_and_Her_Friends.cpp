#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll tstcs;
    cin >> tstcs;
    while(tstcs--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        ll x, y;
        cin >> x >> y;
        ll a[k * 2];
        ll tf = 1;
        for(ll i = 0; i < k * 2; i++)
        {
            cin >> a[i];
        }
        for(ll i = 0; i < k * 2; i += 2)
        {
            if(abs((x - a[i]) + (y - a[i + 1])) % 2 == 0)
            {
                tf = 0;
                break;
            }
        }
        if(tf)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
