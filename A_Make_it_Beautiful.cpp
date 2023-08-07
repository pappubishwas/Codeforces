#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n, a[100], p = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] == a[i + 1])
                p++;
        }
        if (p == n - 1)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            cout << a[n - 1]<<" ";
            for (int i = 0; i < n - 1; i++)
                cout << a[i]<<" ";
            cout<<endl;    
        }
    }
    return 0;
}