#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    int n = 0, m = 0, k = 0,p;
    cin >> p;
    int a[p];
    cin >> a[0];
    if (a[0] == 1)
        n++;
    else
        m++;
    for (int i = 1; i < p; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            n++;
        else
            m++;

        if (a[i - 1] == -1 && a[i] == -1)
            k = 1;
    }
    if (m==0)cout<<n-4<<endl;
    else if(k==1) cout<<n-m+4<<endl;
    else cout<<n-m<<endl;
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