#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n], x[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x[i];
    }
    int temp,l=INT_MAX;
    for (int i = 0; i < m; i++)
    {
        temp = pow(2, x[i]);
        if(l>x[i]){
            l=x[i];
        for (int j = 0;j < n; j++)
        {
            if (a[j] % temp == 0)
            {
                a[j] += pow(2, x[i] - 1);
            }
        }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
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