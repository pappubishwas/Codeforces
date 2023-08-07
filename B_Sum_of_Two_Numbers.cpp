#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    ll n, k = 0, t = 0, i = 0, t1 = 0, j = 0, r = 0;
    cin >> n;
    // k=n;
    ll a[50];
    while (n > 0)
    {
        a[i] = n % 10;
        n = n / 10;
        i++;
    }

    while (j < i)
    {

        if (a[j] % 2 == 0)
        {
            t = (a[j] / 2) * pow(10, r) + t;
            t1 = (a[j] / 2) * pow(10, r) + t1;
            r++;
        }
        else
        {
            if (k % 2 == 0)
            {
                t = (a[j] / 2) * pow(10, r) + t;
                t1 = (a[j] / 2 + 1) * pow(10, r) + t1;
                r++;
                k++;
            }
            else
            {
                t = (a[j] / 2 + 1) * pow(10, r) + t;
                t1 = (a[j] / 2) * pow(10, r) + t1;
                r++;
                k++;
            }
        }
        j++;
    }
    cout<<t<<" "<<t1<<endl;
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