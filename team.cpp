#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    //char p[150][30], ch[150][1];
    int i, n, c = 0, k = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> p[i][30];
    }
    for (i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (p[i][0] == p[j][0])
                c++;
        }
        if (c >= 3)
        {
            ch[k][0] = p[i][0];
                k++;
        }
    }
    if (ch[i][0] == '\0')
        cout << "impossible" << endl;
    else
    {
        k = 0;
        while (ch[k][0] != '\0')
        {
            cout << ch[k][0] << endl;
            k++;
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