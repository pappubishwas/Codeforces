#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve()
{
    ll n, k, c = 0, t = 0, max = 0, min = 0, q = 0,pt=0;
    cin >> n >> k;
    ll a[n][2];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
        if (a[i][0] <= k && a[i][1] >= k)
        {
            c++;
            if(c==1)max=a[i][1];
            if (a[i][0] > min)
                min = a[i][0];
            if (a[i][1] < max)
                max = a[i][1];
        }
    }
    ll b[50];
    for (ll i = min; i <= max; i++)
    {
        t = 0;
        for (ll j = 0; j < n; j++)
        {

            if (a[j][0] <= i && a[j][1] >= i)
            {
                t++;
            }
        }
        if(i==k){
        b[q] = 0;
        // cout<<b[q];
        q++;
        }else{
            b[q]=t;
            q++;
        }
        
    }
    
    sort(b, b + q);
    if (b[q - 1] < c)
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
