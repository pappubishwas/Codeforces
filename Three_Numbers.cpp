#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int p, q, r, maximum = 0;
        cin >> p >> q >> r;
        if (p == q && q == r && r == p)
        {
            cout << 0 << endl;
        }
        else if (p == q || q == r || r == p)
        {
            maximum = max(p, max(q, r));

            if ((maximum - p) >= 2)
            {
                cout << ((maximum - p) / 2) << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}