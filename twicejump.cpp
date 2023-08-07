#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, i, ram=0, raj=0, j = 0, m,k;
    cin >> n;
    m = 2 * n;
    vector <ll> a;
    for (i = 0; i < m; i++)
    {
        cin >> k;
        a.push_back(k);
    }

    for (i = 0; i < m; i = i + 2)
    {
        if (j % 2 == 0)
            raj =raj+ a[i] + a[i + 1];
        else
            ram = ram+a[i] + a[i + 1];
        j++;
    }
    if (raj >= ram)
        cout << "Raj"  << endl;
    else
        cout << "Ram" << endl;
    return 0;
}