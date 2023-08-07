#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve()
{
    long long m;
    cin >> m;
    long long p[m];
    long long x = 0, y = m - 1;
for (int i= 0; i < m; i++)
{
    cin>>p[i];
}

    reverse(r.begin(), r.end());

    if (p == r)
    {
        cout << "Yes" << endl;
        return;
    }

    while (x <= y)
    {
        if (p[x] == p[y])
        {
            x++, y--;
        }
        else
        {
            break;
        }
    }

    while (x <= y)
    {
        if (p[x] != p[y])
        {
            p[x] = p[y];
            x++, y--;
        }
        else
        {
            break;
        }
    }

    r = p;
    reverse(r.begin(), r.end());
    if (p == r)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

int main()
{
    long long tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}