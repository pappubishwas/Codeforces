#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    int n, max, k = 1,p=0;
    cin >> n;
    int a[n][n - 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        k = 1;
        max = a[i][0];
        for (int j = i + 1; j < n; j++)
        {
            if (a[j][0] == max)
                k++;
            if (k > (n / 2)){
                p=1;
                break;
            }
        }
        if(p==1)  break;
    }
    cout << max << " ";
    for (int i = 0; i < n; i++)
    {
        if (max != a[i][0])
        {
            for (int k = 0; k < n - 1; k++)
            {
                cout << a[i][k] << " ";
            }
            cout << endl;
            break;
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